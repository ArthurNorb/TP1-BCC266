#include "cpu.h"
#include "operacoes.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Número de argumentos inválidos! Sao 3.\n");
        printf("Linha de execução: ./exe TIPO_INSTRUCAO [TAMANHO_RAM|ARQUIVO_DE_INSTRUCOES]\n");
        printf("\tExemplo 1 de execução: ./exe random 10\n");
        printf("\tExemplo 2 de execução: ./exe file arquivo_de_instrucoes.txt\n");
        printf("\tExemplo 3 de execução: ./exe menu 10\n");
        return 0;
    }

    Maquina maquina;
    printf("Iniciando máquina...\n");
    menu(&maquina, argv);
    imprimeRAM(&maquina);
    desliga(&maquina);
    printf("Desligando máquina...\n");

    return 0;
}