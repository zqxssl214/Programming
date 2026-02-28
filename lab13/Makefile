.PHONY: all clean

CC = gcc
CFLAGS = -Wall -I./include
TARGET = app
SOURCE_DIR = src/
HDIR = include/

all: $(TARGET)

$(TARGET): main.o auto.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $^ -o $@

auto.o: $(SOURCE_DIR)auto.c $(HDIR)auto.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)