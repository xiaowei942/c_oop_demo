target=test
sources=$(wildcard *.c)
objects=$(subst .c,.o,$(sources))

CC:=gcc
CFLAGS+=-std=c99 -g

all:$(target)

$(target):$(objects)
	$(CC) -o $@ $^

clean:
	-rm $(objects)
