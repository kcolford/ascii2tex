CFLAGS = -O3
LDFLAGS = -s

all: ascii2tex

clean: 
	$(RM) ascii2tex

.PHONY: all clean
