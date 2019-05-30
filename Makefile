CFLAGS=-Wall -Werror -pedantic -std=c++11 -pthread -ggdb -O0 -Iproduct  
LDFLAGS=-pthread 

TEST_LIBS=-lgtest -lgmock -lgmock_main -lpthread

SOURCES=$(wildcard Product/*.cpp)
HEADERS=$(wildcard Product/*.h)

TEST_SOURCES=$(wildcard Test/*.cpp)

SOURCES_INC=-I./Product

CC=/usr/local/xtools/arm-unknown-linux-uclibcgnueabi/bin/arm-linux-g++
TEST_CC=g++

.phony: all clean

all: program test

program: $(SOURCES) $(HEADERS) Makefile 
	@$(CC) $(CFLAGS_NORMAL) main.cpp $(SOURCES) -o $@ $(LDFLAGS)
	
test: $(TEST_SOURCES) $(SOURCES) $(HEADERS) Makefile
	@$(TEST_CC) $(CFLAGS_NORMAL) $(TEST_SOURCES) $(SOURCES) $(SOURCES_INC) -o $@ $(TEST_LIBS)

clean:
	@rm -rf program
	@rm -rf test
