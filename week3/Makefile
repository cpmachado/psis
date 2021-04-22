# See LICENSE for details
.POSIX:

include ../config.mk

HDR = ${wildcard include/*.h}
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
	@rm -rf ${OBJ} ${DEP} ${BIN} *.so *.tar.gz

lint:
	cpplint ${SRC} ${HDR}

# recipes for binaries

infinite-loop: infinite-loop.o
char-conv: char-conv.o


-include ${DEP}
