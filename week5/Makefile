# See LICENSE for details
.POSIX:

include ../config.mk

HDR = ${wildcard include/*.h}
SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
BIN =\
	sprintinc\
	ten\
	tenv2\
	primediv\
	mainEVI\
	workerEVI


all: ${BIN}
	@echo "all built"

clean:
	@echo cleaning
	@rm -rf ${OBJ} ${DEP} ${BIN} *.tar.gz

lint:
	cpplint ${SRC} ${HDR}


# recipes for binaries

sprintinc: sprintinc.o
ten: ten.o
tenv2: tenv2.o

primediv: primediv.o libra.o

mainEVI: mainEVI.o libra.o
workerEVI: workerEVI.o
-include ${DEP}
