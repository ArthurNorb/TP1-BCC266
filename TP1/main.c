#include "cpu.h"
#include "operacoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    double tempoGasto = 0.0;
    clock_t begin = clock();

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

    clock_t end = clock();

    tempoGasto += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("o tempo foi de %f segundos", tempoGasto);

    return 0;
}