CXX = g++

CXXFLAGS = -Wall -O2
SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=)

all: main 2-1 2-2 2-3 2-4 2-5 2-7 2-8 2-9 

test: all
	./main < ../data/name1
	./2-1 <../data/name1
	./2-2 <../data/name1
	./2-3 <../data/2-3
	./2-4 <../data/name1
	./2-5 
	./2-7 
	./2-8 
	./2-9 < ../data/2-9
	make clean

.PHONY: clean
clean:
	rm -f $(OBJS) *.o

	