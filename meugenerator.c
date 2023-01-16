#include "generator.h"
#include <stdio.h>
#include <stdlib.h>

Instruction* lerGerar(char* fileName, int ramSize) {
    // 01|22|13|45 => isto é uma instrução
    // 02|33|12|01 => isto é outra instrução
            
    // 0 => salvar na memória
    // 1 => opcode => somar
    // 2 => opcode => subtrair
    //-1 => halt
    
    // 22 => significa um endereço da RAM (10 endereço) 
    // 13 => significa 2o endereço
    // 45 => significa 3o endereco
    //ramSize => ESTA FORA DO INTERVALO DE 0 A ramSize DA MEMÓRIA RAM
    FILE* file = fopen(fileName, "r"); // Abrindo arquivo pra ler
    if (file == NULL) {
        printf("Arquivo nao pode ser aberto.\n");
        exit(1);
    }

    int n, i = 0;
    fscanf(file, "%d", &n);
    Instruction* instructions = (Instruction*) malloc(n * sizeof(Instruction));
    while (i < n) {
        if(i < n-1) {
            instructions[i].opcode = rand() % 4; // 0, 1, 2, 3
            instructions[i].info1 = rand() % ramSize;
            instructions[i].info2 = rand() % ramSize;
            instructions[i].info3 = rand() % ramSize;
        } else {
            instructions[i].opcode = -1;
            instructions[i].info1 = -1;
            instructions[i].info2 = -1;
            instructions[i].info3 = -1;
        }
        i++;
    }
    fclose(file); // Fechando o arquivo
    return instructions;
}
