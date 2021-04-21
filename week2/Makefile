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
	prog1


all: ${BIN}
	@echo "all built"

clean:
	@echo cleaning
	@rm -rf ${OBJ} ${DEP} ${BIN} *.tar.gz

lint:
	cpplint ${SRC} ${HDR}

# recipes for binaries

echov1: echov1.o
echov2: echov2.o
prog1: prog1.o lib1.o


-include ${DEP}
