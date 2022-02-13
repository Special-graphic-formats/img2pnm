CFLAGS=-Wall -Wextra -pedantic -std=c11 -ggdb

.PHONY: all
all: src/main.c
	$(CC) $(CFLAGS) -o build/img2ppm src/main.c