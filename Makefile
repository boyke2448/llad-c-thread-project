TARGET=./bin/my_program
SRC=$(wildcard src/*.c)
OBJ=$(SRC:src/%.c=obj/%.o)
CFLAGS=-I include -pthread -g3

all: $(TARGET)
clean: 
	rm -rf ./obj/*
	rm -rf ./bin/*

$(TARGET): $(OBJ)
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@
