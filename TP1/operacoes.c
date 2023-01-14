#include "operacoes.h"
#include "cpu.h"

#include <stdio.h>

void multiplicacao(Maquina *maquina)
{


    float num1 = maquina->RAM.enderecos[0];
    float num2 = maquina->RAM.enderecos[1];
    float resultado;

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
    if (num2 < 0)
    {
        num2_mod = -num2;
        maquina->RAM.enderecos[1] = num2_mod;
    }

    for (int i = 0; i < num2_mod; i++)
    {
        roda(maquina);
    }
    resultado = maquina->RAM.enderecos[2];

    if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0))
        resultado = -resultado;

    printf("  > Multiplicado RAM[%d] (%f) com RAM[%d] (%f) e salvo na RAM[%d] (%f).\n", 0, num1, 1, num2, 2, resultado);

}