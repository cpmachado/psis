# See LICENSE for details
# configuration of system

# Compiler options
CC       = gcc
INC     += -I. -I/usr/include
CFLAGS  += -W -Wall -Werror -std=c99 -pedantic -Wno-unused-result ${INC}
CPPFLAGS =\
	-D_POSIX_C_SOURCE=200809L
OUTPUT_OPTION = -MMD -MP
LDFLAGS =


# archive static library
%.a:
	ar rcs $@ $^

%.so:
	gcc -o $@ $^ -ldl -shared -fPIC
