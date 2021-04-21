.POSIX:

SRCDIR = ${wildcard week*}

all:
	@for i in ${SRCDIR};do make -C $$i;done

clean:
	@for i in ${SRCDIR};do make -C $$i clean;done

lint:
	@for i in ${SRCDIR};do make -C $$i lint;done

