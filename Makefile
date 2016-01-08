CC = gcc
CFLAGS = -Wall -std=c99
SHELL = /bin/bash

separator = "=========================================="
# dirs = $(shell ls -d src/**/*/)
dirs = $(shell find src -type d)
sources = $(shell find src -name *.c)
objects = $(sources:src/%.c=bin/%)

.PHONY: all clean
.SECONDARY: main-build

all: pre-build main-build post-build

pre-build:
	@mkdir -p $(dirs:src/%=bin/%)

post-build:

main-build: $(objects)

bin/%: src/%.c
	@printf "\nSTART BUILD $^\n$(separator)\n"
	$(CC) $(CFLAGS) -o $@ $^
	@printf "$(separator)\n\n\n"

clean:
	rm -rf ./bin
