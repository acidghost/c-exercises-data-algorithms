CC := gcc
CFLAGS := -Wall -std=c99
DIRS := $(wildcard src/*)
SOURCES := $(wildcard src/**/*.c)
BINS = $(addprefix bin/, $(SOURCES:src/%.c=%))

.PHONY: all clean
.SECONDARY: main-build

all: pre-build main-build post-build

pre-build:
	@mkdir -p $(DIRS:src/%=bin/%)

post-build:

main-build: $(BINS)

bin/%: src/%.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BINS)
