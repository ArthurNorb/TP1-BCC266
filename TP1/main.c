#include "cpu.h"

#include <stdio.h>

int main()
{
    int tamanho_RAM;
    Maquina maquina;
    // esse bloco serve apenas para testar a máquina
    Instrucao instrucao01;
    instrucao01.opcode = 0; // operação a ser executada (olhar "switch" no cpu.c)
    instrucao01.info1 = 22; // 1º endereço da RAM
    instrucao01.info2 = 13; // 2º endereço da RAM
    instrucao01.info3 = 45; // 3º endereço da RAM
    tamanho_RAM = 1;
    // fim do bloco de testes
    Instrucao instrucoes[1] = {instrucao01};

    printf("Iniciando máquina...\n");
    liga(&maquina, instrucoes, tamanho_RAM);
    imprimeRAM(&maquina);
    roda(&maquina);
    imprimeRAM(&maquina);
    desliga(&maquina);
    printf("Desligando máquina...\n");

    return 0;
}