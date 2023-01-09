#include <stdio.h>
#include "cpu.h"

int main()
{
    int tamanho_RAM;
    Maquina maquina;
    Instrucao *instrucoes;

    printf("Iniciando máquina...");
    liga(&maquina, instrucoes, tamanho_RAM);
    desliga(&maquina);
    printf("\nDesligando máquina...");

    return 0;
}