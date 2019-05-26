CFLAGS=-Wall -Werror -pedantic -std=gnu++11 -ggdb -O0 -Iproduct  
LDFLAGS=-pthread 

TEST_LIBS=-lgtest -lgmock -lgmock_main -lpthread

SOURCES=$(wildcard Product/*.cpp)
HEADERS=$(wildcard Product/*.h)

SOURCES_INC=-I./Product

CC=/usr/local/xtools/arm-unknown-linux-uclibcgnueabi/bin/arm-linux-g++

.phony: all clean

all: program

program: $(SOURCES) $(HEADERS) Makefile 
	@$(CC) $(CFLAGS_NORMAL) main.cpp $(SOURCES) -o $@ $(LDFLAGS)
	

clean:
	@rm -rf program
