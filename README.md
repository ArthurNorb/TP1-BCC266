# TP1 BCC266
Primeiro trabalho prático de Organização de Computadores da UFOP, desenvolvido por Arthur Norberto, Gabriel Maia e Marcelo.

## Proposta
A proposta do TP pode ser encontrada no arquivo TPI.pdf, que basicamente pede para o grupo fazer uma calculadora imitando a linguagem de máquina. Tentaremos desenvolver um código que execute todas as funções demonstradas na figura 1 do arquivo.

![Captura de tela de 2023-01-07 03-25-06](https://user-images.githubusercontent.com/111247268/211134547-c7c03e57-ca80-463e-93fc-2f89596d48eb.png)

## Source
A pasta "Source" contém o código deixado pelo professor Pedro Silva para servir de base no nosso trabalho, o intuito é refazer sem copiar exatamente o que foi deixado pelo professor.

## Compilação
Para compilar e executar o programa, basta ir no terminal e usar os seguintes comandos:
> $ make all
> $ ./exe
Ou se preferir pode compilar do modo padrão:
> $ gcc -c operacoes.c -Wall
> $ gcc -c cpu.c -Wall
> $ gcc -c main.c -Wall
> $ gcc operacoes.o cpu.o main.o -o exe
> $ ./exe

