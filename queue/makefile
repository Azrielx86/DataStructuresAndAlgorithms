CC=clang++

queue: main.o queue.o
	@$(CC) main.o queue.o -o Queue

queue.o:
	@$(CC) -c queue.cpp -o queue.o

main.o:
	@$(CC) -c main.cpp -o main.o

clean:
	@rm *.o Queue