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
        maquina->RAM.enderecos[i] = (float)rand() / RAND_MAX; // aleatoriza o endereço da RAM para um numero decimal
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
            infoParaRAM(instrucao, maquina);
            break;
        case 1: // soma
            soma(instrucao, maquina);
            break;
        case 2: // subtração
            subtracao(instrucao, maquina);
            break;
        }
        PC++;
        // loop não chega ao fim.
    }
}

void imprimeRAM(Maquina *maquina)
{
    printf("  > RAM");
    for (int i = 0; i < maquina->RAM.tamanho; i++)
        printf("\t\t[%5d] : %f\n", i, maquina->RAM.enderecos[i]);
}