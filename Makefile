CFLAGS=-Wall -Werror -pedantic  -ggdb -O0 -Iproduct 
LDFLAGS=-pthread 

TEST_LIBS=-lgtest -lgmock -lgmock_main -lpthread

SOURCES=$(wildcard Product/*.cpp)
HEADERS=$(wildcard Product/*.h)

SOURCES_INC=-I./Product

CC=g++

.phony: all clean

all: program

program: $(SOURCES) $(HEADERS) Makefile 
	@$(CC) $(CFLAGS_NORMAL) main.cpp $(SOURCES) -o $@ $(LDFLAGS)
	

clean:
	@rm -rf program