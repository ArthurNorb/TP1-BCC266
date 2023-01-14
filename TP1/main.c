#include "cpu.h"
#include "operacoes.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    Maquina maquina;
    printf("Iniciando máquina...\n");
    menu(&maquina);
    imprimeRAM(&maquina);
    desliga(&maquina);
    printf("Desligando máquina...\n");

    return 0;
}