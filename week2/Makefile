# See LICENSE for details
.POSIX:

include ../config.mk

SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
BIN =\
	echov1\
	echov2


all: ${BIN}
	@echo "all built"

clean:
	@echo cleaning
	@rm -rf ${OBJ} ${DEP} ${BIN} *.tar.gz

lint:
	cpplint ${SRC}

# recipes for binaries

echov1: echov1.o
echov2: echov2.o


-include ${DEP}
