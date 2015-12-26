target=test
sources=$(wildcard *.c)
objects=$(subst .c,.o,$(sources))

CC:=gcc
CFLAGS+=-std=c99

all:$(target)

$(target):$(objects)
	$(CC) $@ $^

clean:
	-rm $(objects)
