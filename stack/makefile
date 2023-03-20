CC=clang++

Stack: main.o stack.o
	@$(CC) main.o stack.o -o Stack

stack.o:
	@$(CC) -c stack.cpp -o stack.o

main.o:
	@$(CC) -c main.cpp -o main.o

clean:
	@rm *.o Stack