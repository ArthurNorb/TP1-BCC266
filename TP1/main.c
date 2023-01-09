#include "cpu.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho_RAM;
    Maquina maquina;
    Instrucao *instrucoes = (Instrucao *)malloc(2 * sizeof(Instrucao));

    // esse bloco serve apenas para testar a máquina
    Instrucao instrucao01;
    instrucao01.opcode = 2; // operação a ser executada (olhar "switch" no cpu.c)
    instrucao01.info1 = 0;  // 1º endereço da RAM
    instrucao01.info2 = 1; // 2º endereço da RAM
    instrucao01.info3 = 0;  // 3º endereço da RAM
    tamanho_RAM = 5;
    Instrucao instrucao02;
    instrucao02.opcode = -1; // operação a ser executada (olhar "switch" no cpu.c)
    instrucao02.info1 = -1;  // 1º endereço da RAM
    instrucao02.info2 = -1;  // 2º endereço da RAM
    instrucao02.info3 = -1;  // 3º endereço da RAM

    instrucoes[0].opcode = instrucao01.opcode;    
    instrucoes[0].info1 = instrucao01.info1;
    instrucoes[0].info2 = instrucao01.info2;
    instrucoes[0].info3 = instrucao01.info3;
    instrucoes[1].opcode = instrucao02.opcode;    
    instrucoes[1].info1 = instrucao02.info1;
    instrucoes[1].info2 = instrucao02.info2;
    instrucoes[1].info3 = instrucao02.info3;
    // fim do bloco de testes

    printf("Iniciando máquina...\n");
    liga(&maquina, instrucoes, tamanho_RAM);
    imprimeRAM(&maquina);
    roda(&maquina);
    imprimeRAM(&maquina);
    desliga(&maquina);
    printf("Desligando máquina...\n");

    return 0;
}