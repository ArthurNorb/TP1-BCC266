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
    float conteudoRAM1, conteudoRAM2;    // informa o conteudo dos endereços 1 e 2
    float resultado;

    endereco1 = instrucao.info1; 
    endereco2 = instrucao.info2;
    conteudoRAM1 = maquina->RAM.enderecos[endereco1];
    conteudoRAM2 = maquina->RAM.enderecos[endereco2];
    resultado = conteudoRAM1 + conteudoRAM2;
    endereco3 = instrucao.info3;
    maquina->RAM.enderecos[endereco3] = resultado;
    printf("  > Somando RAM[%d] (%f) com RAM[%d] (%f) r salvando na RAM[%d] (%f).\n",
           endereco1, conteudoRAM1, endereco2, conteudoRAM2, endereco3, resultado);
}

void subtracao(Instrucao instrucao, Maquina *maquina)
{
    int endereco1, endereco2, endereco3; // pega os 3 endereços de cada instrução
    float conteudoRAM1, conteudoRAM2;    // informa o conteudo dos endereços 1 e 2
    float resultado;

    endereco1 = instrucao.info1;
    endereco2 = instrucao.info2;
    conteudoRAM1 = maquina->RAM.enderecos[endereco1];
    conteudoRAM2 = maquina->RAM.enderecos[endereco2];
    resultado = conteudoRAM1 - conteudoRAM2;
    endereco3 = instrucao.info3;
    maquina->RAM.enderecos[endereco3] = resultado;
    printf("  > Somando RAM[%d] (%f) com RAM[%d] (%f) r salvando na RAM[%d] (%f).\n",
           endereco1, conteudoRAM1, endereco2, conteudoRAM2, endereco3, resultado);
}