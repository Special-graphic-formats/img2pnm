#!/bin/sh

set -xe

CFLAGS="-Wall -Wextra -pedantic -std=c11 -ggdb"
CLIBS="-lm"
cc -o $CFLAGS $CLIBS -o build/img2pnm src/ppm.c src/main.c