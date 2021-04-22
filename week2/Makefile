# See LICENSE for details
.POSIX:

include ../config.mk

HDR = ${wildcard include/*.h}
SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
BIN =\
	echov1\
	echov2\
	prog1\
	prog2


all: ${BIN}
	@echo "all built"

clean:
	@echo cleaning
	@rm -rf ${OBJ} ${DEP} ${BIN} *.so *.tar.gz

lint:
	cpplint ${SRC} ${HDR}

# recipes for binaries

echov1: echov1.o
echov2: echov2.o
prog1: prog1.o lib1.o

lib1.so: lib1.o
lib2.so: lib2.o
prog2: prog2.o lib1.so lib2.so
	${CC} -o $@ $< -ldl



-include ${DEP}
