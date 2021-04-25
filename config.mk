# See LICENSE for details
# configuration of system

# Compiler options
CC      ?= gcc
INC     += -I. -I/usr/include
CFLAGS  += -W -Wall -Werror -std=c99 -Wno-unused-result ${INC}
CPPFLAGS =\
	-D_POSIX_C_SOURCE=200809L\
	-D_XOPEN_SOURCE=700

OUTPUT_OPTION = -MMD -MP
LDFLAGS = -ldl -pthread


# archive static library
%.a:
	ar rcs $@ $^

%.so:
	${CC} -o $@ $^ ${LDFLAGS} -shared -fPIC


