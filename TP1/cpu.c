#include "cpu.h"
#include "operacoes.h"

#include <stdio.h>
#include <stdlib.h>

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
            printf(" > Finalizando a execução.\n");
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
            printf("  > Somando RAM[%d] (%f) com RAM[%d] (%f) e salvando na RAM[%d] (%f).\n", endereco1, conteudoRAM1, endereco2, conteudoRAM2, endereco3, resultado);
        }
        break;
    }
    PC++;
}

void imprimeRAM(Maquina *maquina)
{
    printf("  > RAM");
    for (int i = 0; i < maquina->RAM.tamanho; i++)
        printf("\t\t[%5d] : %f\n", i, maquina->RAM.enderecos[i]);
}