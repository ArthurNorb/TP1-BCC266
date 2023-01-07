#include "cpu.h"
#include <stdio.h>
#include <stdlib.h>

void inicia(Maquina *maquina, Instrucao *instrucoes, int tamanhoRAM)
{
    maquina->instrucoes = instrucoes; // lê instruções do usuário
    maquina->RAM.endereco = (float *)malloc(tamanhoRAM * sizeof(float)); // aloca memória RAM
    maquina->RAM.tamanho = tamanhoRAM;
    for (int i = 0; i < tamanhoRAM; i++)
        maquina->RAM.endereco[i] = (float)rand() / RAND_MAX; // aleatoriza o endereço da RAM para um numero decimal
}

void para(Maquina *maquina);

void roda(Maquina *maquina);

void imprimeRAM(Maquina *);