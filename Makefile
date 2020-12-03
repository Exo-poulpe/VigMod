CC = gcc
CFLAGS = -Wall -Wextra --std=c11

VigMod: VigMod.o Alpha.o main.o 
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -o $@ -c $^

VigMod.o: VigMod.c
	$(CC) $(CFLAGS) -o $@ -c $^

Alpha.o: Alpha.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -rf *.o
	rm -rf VigMod