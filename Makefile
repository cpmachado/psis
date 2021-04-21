
SRCDIR = ${wildcard week*}

all:
	@for i in ${SRCDIR};do make -C $$i;done

lint:
	@for i in ${SRCDIR};do make -C $$i lint;done
