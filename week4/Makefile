# See LICENSE for details
.POSIX:

include ../config.mk

SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
BIN =\
	cat-fork\
	rand-parent\
	rand-parentv2


all: ${BIN}
	@echo "all built"

clean:
	@echo cleaning
	@rm -rf ${OBJ} ${DEP} ${BIN} *.tar.gz

lint:
	cpplint ${SRC}

# recipes for binaries

cat-fork: cat-fork.o
rand-parent: rand-parent.o
rand-parentv2: rand-parentv2.o


-include ${DEP}
