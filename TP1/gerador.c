#include "gerador.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Instrucao *geraInstrucoesAleatorias(int tamanhoRAM)
{
    // 01|22|13|45 => isto é uma instrução
    // 02|33|12|01 => isto é outra instrução

    // 0 => salvar na memória
    // 1 => opcode => somar
    // 2 => opcode => subtrair
    //-1 => halt

    // 22 => significa um endereço da RAM (10 endereço)
    // 13 => significa 2o endereço
    // 45 => significa 3o endereco
    // ramSize => ESTA FORA DO INTERVALO DE 0 A ramSize DA MEMÓRIA RAM
    srand(time(NULL));
    Instrucao *instrucoes = (Instrucao *)malloc(10 * sizeof(Instrucao));

    for (int i = 0; i < 9; i++)
    {
        instrucoes[i].opcode = rand() % 3;         // 0, 1 ou 2 (levar para memória, adição e subtração)
        instrucoes[i].info1 = rand() % tamanhoRAM; // 0 até o maximo da RAM
        do
        {
            instrucoes[i].info2 = rand() % tamanhoRAM;
        } while (instrucoes[i].info1 == instrucoes[i].info2);
        instrucoes[i].info3 = rand() % tamanhoRAM;
    }

    // ultima instrução para acabar com o loop
    instrucoes[9].opcode = -1;
    instrucoes[9].info1 = -1;
    instrucoes[9].info2 = -1;
    instrucoes[9].info3 = -1;

    return instrucoes;
}

Instrucao *leInstrucoes(char *nomeArquivo, int *tamanhoRAM)
{
    Instrucao *instrucoes = (Instrucao *)malloc(10 * sizeof(Instrucao));
    return instrucoes;
}