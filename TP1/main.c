#include "cpu.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanhoRAM;
    printf("INSIRA O TAMANHO DA RAM: ");
    scanf("%d", &tamanhoRAM);

    Maquina maquina;
    printf("Iniciando máquina...\n");
    menu(&maquina, tamanhoRAM);
    imprimeRAM(&maquina);
    desliga(&maquina);
    printf("Desligando máquina...\n");

    return 0;
}