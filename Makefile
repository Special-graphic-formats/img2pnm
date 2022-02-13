CFLAGS=-Wall -Wextra -pedantic -std=c11 -ggdb
CLIBS=-lm

.PHONY: all
all: src/main.c
	$(CC) $(CFLAGS) $(CLIBS) -o build/img2pnm src/ppm.c src/main.c