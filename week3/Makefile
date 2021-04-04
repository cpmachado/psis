# See LICENSE for details
.POSIX:

CFLAGS = -g -O0

include ../config.mk

HDR = ${wildcard include/*.h}
SRC = ${wildcard *.c}
SRC_LIB = ${wildcard lib*.c}
OBJ = ${SRC:.c=.o} ${SRC_LIB:.c=.so}
DEP = ${SRC:.c=.d}
BIN =\
	 infinite-loop\
	 char-conv\
	 producer\
	 consumer


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

libSingleStep.so: libSingleStep.o
randarray.o: randarray.c
producer: producer.o randarray.o
consumer: consumer.o libSingleStep.so

-include ${DEP}
