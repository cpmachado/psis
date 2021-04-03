# See LICENSE for details
.POSIX:

CFLAGS = -g -O0

include ../config.mk

SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
BIN =\
	 infinite-loop\
	 char-conv


all: ${BIN}
	@echo "all built"

clean:
	@echo cleaning
	@rm -rf ${OBJ} ${DEP} ${BIN} *.tar.gz

lint:
	cpplint ${SRC} ${HDR}

# recipes for binaries
infinite-loop: infinite-loop.o
char-conv: char-conv.o

-include ${DEP}
