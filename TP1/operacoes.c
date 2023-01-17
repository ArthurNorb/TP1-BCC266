#include "operacoes.h"
#include "cpu.h"

#include <stdio.h>
#include <math.h>

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
    int contadorDecimais = 0;
    int k = 0;
    while ((num1_mod != 0) && (contadorDecimais <= 5))
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
            contadorDecimais++;
            k++;
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
        printf("%f", resto);
    }

    if (k == 0)
    {
        resultado = quociente;
    }
    else
        resultado = quociente * pow(0.1, k);

    if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0))
        resultado = -resultado;

    maquina->RAM.enderecos[2] = resultado;

    return resultado;
}

float potencia(Maquina *maquina)
{
    // multiplicar num1 com o proprio resultado com 1, até atingir seu expoente

    float num1 = maquina->RAM.enderecos[0];
    float num2 = maquina->RAM.enderecos[1];
    int expoente = 0;
    float resultado = 1;

    if (num2 == 0)
        return 1;
    else
    {
        do
        {
            maquina->RAM.enderecos[1] = resultado;
            resultado = multiplicacao(maquina);

            maquina->RAM.enderecos[0] = expoente;
            maquina->RAM.enderecos[1] = 1;
            roda(maquina);
            expoente = maquina->RAM.enderecos[2];

            maquina->RAM.enderecos[0] = num1;
        } while (expoente <= num2);
    }
    return resultado;
}