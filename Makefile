CC = gcc
CFLAGS = -Wall -Wextra --std=c11
SsANIT = -g -pedantic -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize-address-use-after-scope

VigMod: argparse.o VigMod.o Alpha.o main.o 
	$(CC) $(CFLAGS) -o $@ $^ $(SANIT)

main.o: main.c
	$(CC) $(CFLAGS) -o $@ -c $^

VigMod.o: VigMod.c
	$(CC) $(CFLAGS) -o $@ -c $^

Alpha.o: Alpha.c
	$(CC) $(CFLAGS) -o $@ -c $^

argparse.o: argparse.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -rf *.o
	rm -rf VigMod

rebuild: clean VigMod