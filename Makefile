TARGET=./bin/my_program
SRC=$(wildcard src/*.c)
OBJ=$(SRC:src/%.c=obj/%.o)
CFLAGS=-Wall -Wextra -I inc -pthread

all: $(TARGET)
clean:
	rm -rf ./bin/*
	rm -rf ./obj/*

$(TARGET): $(OBJ)
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@
