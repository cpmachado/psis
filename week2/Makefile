# See LICENSE for details
.POSIX:

include ../config.mk

HDR = ${wildcard include/*.h}
SRC = ${wildcard *.c}
SRC_LIB = ${wildcard lib*.c}
OBJ = ${SRC:.c=.o} ${SRC_LIB:.c=.so}
DEP = ${SRC:.c=.d}
BIN =\
	ex1\
	ex2\
	prog1\
	prog2\
	ex6\
	ex7


all: ${BIN}
	@echo "all built"

clean:
	@echo cleaning
	@rm -rf ${OBJ} ${DEP} ${BIN} *.tar.gz

lint:
	cpplint ${SRC} ${HDR}

# recipes for binaries

ex1: ex1.o
ex2: ex2.o
prog1: prog1.o lib1.o

lib1.so: lib1.o
lib2.so: lib2.o
prog2: prog2.o lib1.so lib2.so

libSingleStep.so: libSingleStep.o
randarray.o: randarray.c
ex6: ex6.o randarray.o libSingleStep.so


libMultiStep.so: libMultiStep.o
ex7: ex7.o randarray.o libMultiStep.so

-include ${DEP}
