#include "operacoes.h"

#include <stdio.h>

void infoParaRAM(Instrucao instrucao, Maquina *maquina)
{
    float valor;
    int endereco1;

    valor = (float)instrucao.info1;
    endereco1 = instrucao.info2;
    maquina->RAM.enderecos[endereco1] = valor;
    printf("  > Levando informação (%f) para a RAM[%d].\n", valor, endereco1);
}

void soma(Instrucao instrucao, Maquina *maquina)
{
    int endereco1, endereco2, endereco3; // pega os 3 endereços de cada instrução

    endereco1 = instrucao.info1;
    endereco2 = instrucao.info2;
}

void subtracao(Instrucao instrucao);