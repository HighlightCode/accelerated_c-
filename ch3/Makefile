CXX = g++

CXXFLAGS = -Wall -O2
SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=)

all: main 3-2 3-3 3-4 3-5 3-6

test:	all
	./main < ../data/avg
	./3-2 < ../data/3-2
	./3-3 < ../data/3-3
	./3-4 < ../data/3-4
	./3-5 < ../data/3-5
	./3-6 < ../data/3-6
	make clean

.PHONY:
	clean

clean:
	rm -f *.o $(OBJS)