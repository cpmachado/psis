# See LICENSE for details
.POSIX:

include ../config.mk

SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
BIN =\
	infinite-loop\
	char-conv\
	producerv1\
	consumerv1\
	producerv2\
	consumerv2\
	char-conv-prob\
	char-conv-uninit


all: ${BIN}
	@echo "all built"

clean:
	@echo cleaning
	@rm -rf ${OBJ} ${DEP} ${BIN} *.a *.tar.gz

lint:
	cpplint --recursive .

# recipes for binaries

infinite-loop: infinite-loop.o
char-conv: char-conv.o

libra.a: libss.o libra.o
producerv1: producerv1.o libra.a
consumerv1: consumerv1.o libra.a

producerv2: producerv2.o libra.a
consumerv2: consumerv2.o libra.a

char-conv-prob: char-conv-prob.o

char-conv-uninit: char-conv-uninit.o

-include ${DEP}
