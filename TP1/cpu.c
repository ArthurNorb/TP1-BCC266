#include "cpu.h"
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
    //free(maquina->instrucoes);
    free(maquina->RAM.enderecos);
}

void roda(Maquina *maquina);

void imprimeRAM(Maquina *);