all: main.o cpu.o operacoes.o gerador.o
	@gcc operacoes.o gerador.o cpu.o main.o -o exe
	rm -r *.o
main.o: main.c
	@gcc -c main.c -Wall
cpu.o: cpu.c
	@gcc -c cpu.c -Wall
operacoes.o: operacoes.c
	@gcc -c operacoes.c -Wall
gerador.o: 
	@gcc -c gerador.c -Wall
run:
	@./exe