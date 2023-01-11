all: main.o cpu.o operacoes.o
	@gcc operacoes.o cpu.o main.o -o exe
	rm -r *.o
main.o: main.c
	@gcc -c main.c -Wall
cpu.o: cpu.c
	@gcc -c cpu.c -Wall
operacoes.o: operacoes.o
	@gcc -c operacoes.c -Wall
run:
	@./exe