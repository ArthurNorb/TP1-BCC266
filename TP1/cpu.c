#include "cpu.h"
#include "operacoes.h"
#include "gerador.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void liga(Maquina *maquina, Instrucao *instrucoes, int tamanhoRAM) // aloca a RAM
{
    maquina->instrucoes = instrucoes; // lê instruções do usuário
    maquina->RAM.enderecos = (float *)malloc(tamanhoRAM * sizeof(float));
    maquina->RAM.tamanho = tamanhoRAM;
    for (int i = 0; i < tamanhoRAM; i++)
        maquina->RAM.enderecos[i] = (float)rand() / RAND_MAX; // aleatoriza o conteudo da RAM para um numero aleatório
}

void desliga(Maquina *maquina) // desaloca a RAM
{
    free(maquina->instrucoes);
    free(maquina->RAM.enderecos);
}

void roda(Maquina *maquina)
{
    int PC = 0;     // Contador de programa, permite executar as instruções em sequência
    int opcode = 0; // para inicializar o loop de instruçoes
    float valor;
    int endereco1, endereco2, endereco3; // pega os 3 endereços de cada instrução
    float conteudoRAM1, conteudoRAM2;    // informa o conteudo dos endereços 1 e 2
    float resultado;

    while (opcode != -1) // roda a máquina enquanto opcode é diferente de -1
    {
        Instrucao instrucao = maquina->instrucoes[PC]; // recebe a instrução
        opcode = instrucao.opcode;                     // opcode atualiza com a instrução

        switch (opcode)
        {
        case -1:
            printf("  > Finalizando a execução.\n");
            break;
        case 0: // leva informação para a RAM
            valor = (float)instrucao.info1;
            endereco1 = instrucao.info2;
            maquina->RAM.enderecos[endereco1] = valor;
            printf("  > Levando informação (%f) para a RAM[%d].\n", valor, endereco1);
            break;
        case 1: // soma
            endereco1 = instrucao.info1;
            endereco2 = instrucao.info2;
            conteudoRAM1 = maquina->RAM.enderecos[endereco1];
            conteudoRAM2 = maquina->RAM.enderecos[endereco2];
            resultado = conteudoRAM1 + conteudoRAM2;
            endereco3 = instrucao.info3;
            maquina->RAM.enderecos[endereco3] = resultado;
            printf("  > Somando RAM[%d] (%f) com RAM[%d] (%f) e salvando na RAM[%d] (%f).\n", endereco1, conteudoRAM1, endereco2, conteudoRAM2, endereco3, resultado);
            break;
        case 2: // subtração
            endereco1 = instrucao.info1;
            endereco2 = instrucao.info2;
            conteudoRAM1 = maquina->RAM.enderecos[endereco1];
            conteudoRAM2 = maquina->RAM.enderecos[endereco2];
            resultado = conteudoRAM1 - conteudoRAM2;
            endereco3 = instrucao.info3;
            maquina->RAM.enderecos[endereco3] = resultado;
            printf("  > Subtraindo RAM[%d] (%f) com RAM[%d] (%f) e salvando na RAM[%d] (%f).\n", endereco1, conteudoRAM1, endereco2, conteudoRAM2, endereco3, resultado);
            break;
        }
        PC++;
    }
}

void imprimeRAM(Maquina *maquina)
{
    printf("\n  > RAM");
    for (int i = 0; i < maquina->RAM.tamanho; i++)
        printf("\t\t[%5d] : %f\n", i, maquina->RAM.enderecos[i]);
}

void menu(Maquina *maquina, int tamanhoRAM)
{
    int opcao_menu;
    float num1, num2, resultado;
    Instrucao *instrucao;

    printf("\nMENU:\n\n");
    printf("Escolha uma opção abaixo:\n0 - Programa Aleatório\n1 - Adição\n2 - Subtração\n3 - Multiplicação\n4 - Potenciação:  ");
    scanf("%d", &opcao_menu);

    switch (opcao_menu)
    {
    case 0: // Programa Aleatório
        instrucao = geraInstrucoesAleatorias(tamanhoRAM);

        liga(maquina, instrucao, tamanhoRAM);
        imprimeRAM(maquina);
        roda(maquina);
        break;
    case 1: // Adição
        // coloca os numeros do usuário na memória
        printf("\nDigite os 2 numeros que deseja somar: ");
        scanf("%f%f", &num1, &num2);

        instrucao = instrucaoDoUsuario(maquina, 1); // recebe instrução do usuário
        liga(maquina, instrucao, tamanhoRAM);
        maquina->RAM.enderecos[0] = num1; // altera o conteúdo da RAM
        maquina->RAM.enderecos[1] = num2;
        imprimeRAM(maquina);
        roda(maquina);
        break;

    case 2: // Subtração
        printf("\nDigite os 2 numeros que deseja somar: ");
        scanf("%f%f", &num1, &num2);

        instrucao = instrucaoDoUsuario(maquina, 2);

        liga(maquina, instrucao, tamanhoRAM);
        maquina->RAM.enderecos[0] = num1;
        maquina->RAM.enderecos[1] = num2;
        imprimeRAM(maquina);
        roda(maquina);
        break;

    case 3: // Multiplicação
        printf("\nDigite os 2 numeros que deseja multiplicar: ");
        scanf("%f%f", &num1, &num2);

        instrucao = instrucaoDoUsuario(maquina, 1);

        liga(maquina, instrucao, tamanhoRAM);
        maquina->RAM.enderecos[0] = num1;
        maquina->RAM.enderecos[1] = num2;
        maquina->RAM.enderecos[2] = 0; // zerando info3
        imprimeRAM(maquina);
        resultado = multiplicacao(maquina);
        printf("\n  > Multiplicado RAM[%d] (%f) com RAM[%d] (%f) e salvo na RAM[%d] (%f).\n", 0, num1, 1, num2, 2, resultado);
        break;

    case 4: // potencia
        printf("\nDigite os 2 numeros (base e exponente): ");
        scanf("%f%f", &num1, &num2);

        instrucao = instrucaoDoUsuario(maquina, 1);

        liga(maquina, instrucao, tamanhoRAM);
        maquina->RAM.enderecos[0] = num1;
        maquina->RAM.enderecos[1] = num2;
        maquina->RAM.enderecos[2] = 0; 
        imprimeRAM(maquina);
        resultado = potencia(maquina);
        printf("\n  > A potência de RAM[%d] (%f) elevado a RAM[%d] (%f) foi salvo na RAM[%d] (%f).\n\n", 0, num1, 1, num2, 2, resultado);
        break;
    default:
        printf("Erro grave... finalizando.");
        exit(1);
        break;
    }
}

Instrucao *instrucaoDoUsuario(Maquina *maquina, int opcode)
{
    Instrucao *instrucoes = (Instrucao *)malloc(2 * sizeof(Instrucao));
    Instrucao instrucao;
    instrucao.opcode = opcode;
    instrucao.info1 = 0;
    instrucao.info2 = 1;
    instrucao.info3 = 2;

    Instrucao instrucaoFinal;
    instrucaoFinal.opcode = -1;
    instrucaoFinal.info1 = -1;
    instrucaoFinal.info2 = -1;
    instrucaoFinal.info3 = -1;

    instrucoes[0] = instrucao;
    instrucoes[1] = instrucaoFinal;

    return instrucoes;
}