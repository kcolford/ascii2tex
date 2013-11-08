CFLAGS = -O3
LDFLAGS = -s

all: ascii2tex archive.tar.gz

archive.tar.gz: README LICENSE Makefile ascii2tex.c
	tar cf $(basename $@) $^ && gzip -f9 $(basename $@)

clean: 
	$(RM) ascii2tex archive.tar.gz

.PHONY: all clean
