# See LICENSE for details
.POSIX:

include ../config.mk

HDR = ${wildcard include/*.h}
SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
BIN =\
	cat-fork\
	rand-parent\
	rand-parentv2\
	primediv


all: ${BIN}
	@echo "all built"

clean:
	@echo cleaning
	@rm -rf ${OBJ} ${DEP} ${BIN} *.tar.gz

lint:
	cpplint ${SRC} ${HDR}

# recipes for binaries

cat-fork: cat-fork.o
rand-parent: rand-parent.o
rand-parentv2: rand-parentv2.o

primediv: primediv.o libra.o

-include ${DEP}
