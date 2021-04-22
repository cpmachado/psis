# See LICENSE for details
.POSIX:

include ../config.mk

HDR = ${wildcard include/*.h}
SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
BIN =\
	infinite-loop\
	char-conv\
	producerv1\
	consumerv1


all: ${BIN}
	@echo "all built"

clean:
	@echo cleaning
	@rm -rf ${OBJ} ${DEP} ${BIN} *.a *.tar.gz

lint:
	cpplint ${SRC} ${HDR}

# recipes for binaries

infinite-loop: infinite-loop.o
char-conv: char-conv.o

libra.a: libss.o libra.o
producerv1: producerv1.o libra.a
consumerv1: consumerv1.o libra.a

-include ${DEP}
