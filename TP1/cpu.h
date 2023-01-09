#ifndef CPU_H
#define CPU_H

typedef struct
{
    int opcode;
    int info1;
    int info2; 
    int info3; 
} Instrucao;

typedef struct {
    float *enderecos;
    int tamanho;
} Memoria;

typedef struct {
    Instrucao* instrucoes;
    Memoria RAM;
} Maquina;

void liga(Maquina*, Instrucao*, int);

void desliga(Maquina*);

void roda(Maquina*);

void imprimeRAM(Maquina*);
//basicamente uma cópia da source

#endif // CPU_H