#include "operacoes.h"
#include "cpu.h"

#include <stdio.h>

float multiplicacao(Maquina *maquina)
{
    float resultado;
    float num1 = maquina->RAM.enderecos[0];
    float num2 = maquina->RAM.enderecos[1];
    maquina->instrucoes->info2 = 2; // altera local onde salva o resultado

    // qualquer número multiplicado por 0 é 0
    if (num1 == 0 || num2 == 0)
        resultado = 0;

    // pega o módulo dos numeros
    float num1_mod, num2_mod;
    if (num1 < 0)
    {
        num1_mod = -num1;
        maquina->RAM.enderecos[0] = num1_mod;
    }
    else
        num1_mod = num1;
    if (num2 < 0)
    {
        num2_mod = -num2;
        maquina->RAM.enderecos[1] = num2_mod;
    }
    else
        num2_mod = num2;

    for (int i = 0; i < num2_mod; i++)
    {
        roda(maquina);
    }
    resultado = maquina->RAM.enderecos[0];

    if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0))
        resultado = -resultado;

    return resultado;
}

float divisao(Maquina *maquina)
{
    float resultado;
    float num1 = maquina->RAM.enderecos[0];
    float num2 = maquina->RAM.enderecos[1];
    if (num1 == 0 || num2 == 0)
        resultado = 0;

    float num1_mod, num2_mod;
    if (num1 < 0)
    {
        num1_mod = -num1;
        maquina->RAM.enderecos[0] = num1_mod;
    }
    else
        num1_mod = num1;
    if (num2 < 0)
    {
        num2_mod = -num2;
        maquina->RAM.enderecos[1] = num2_mod;
    }
    else
        num2_mod = num2;

    float resto, quociente;
    while (resto != 0)
    {
        // adiciona 0 no final do dividendo
        if (num1_mod < num2_mod)
        {
            maquina->instrucoes->opcode = 1;
            maquina->RAM.enderecos[1] = 10;
            num1_mod = multiplicacao(maquina);
            maquina->instrucoes->opcode = 2;
            maquina->RAM.enderecos[1] = num2_mod;
            maquina->RAM.enderecos[2] = 0; // zera novamente o resultado
        }

        maquina->instrucoes->opcode = 1;
        for (int i = 1; i <= num1_mod; i++)
        {
            maquina->RAM.enderecos[0] = i;
            if (multiplicacao(maquina) == num1_mod)
                quociente = i;
                i = num1_mod; // acaba o for
            if (multiplicacao(maquina) > num1_mod)
                quociente = i - 1;
                i = num1_mod;
        }

        maquina->instrucoes->opcode = 2;
        maquina->RAM.enderecos[0] = num1_mod;
        maquina->RAM.enderecos[1] = quociente;
        roda(maquina);
        resto = maquina->RAM.enderecos[2]; 

    }

    resultado = maquina->RAM.enderecos[0];

    if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0))
        resultado = -resultado;

    return resultado;
}