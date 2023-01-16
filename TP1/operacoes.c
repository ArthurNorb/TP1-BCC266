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

    float resto = num1_mod;
    float quociente;
    while (num1_mod != 0)
    {
        // adiciona 0 no final do dividendo quando for menor que o divisor
        if (num1_mod < num2_mod)
        {
            maquina->instrucoes->opcode = 1;
            maquina->RAM.enderecos[1] = 10;
            num1_mod = multiplicacao(maquina);
            maquina->instrucoes->opcode = 2;
            maquina->RAM.enderecos[1] = num2_mod;
            num1_mod = maquina->RAM.enderecos[2];
            maquina->RAM.enderecos[2] = 0; // zera novamente o resultado
        }

        // procura o valor do quociente
        for (int i = 0; i < num1_mod; i++)
        {
            if (num2_mod * i == num1_mod)
            {
                quociente = i;
                resto = 0;
                break;
            }
            if (num2_mod * i > num1_mod)
            {
                quociente = i - 1;
                resto = num1_mod - (num2_mod * quociente);
                break;
            }

        }

        num1_mod = resto;
    }

    resultado = quociente;

    if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0))
        resultado = -resultado;

    return resultado;
}