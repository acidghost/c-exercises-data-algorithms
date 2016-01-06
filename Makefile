CFLAGS := -Wall
SOURCES := $(wildcard src/*.c)
BINS = $(addprefix bin/,$(notdir $(SOURCES:.c=)))

all: $(BINS)

bin/%: src/%.c
	gcc $(CFLAGS) -o $@ $^

clean:
	rm bin/*
