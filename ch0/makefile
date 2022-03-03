CXX = g++

CXXFLAGS = -Wall -O2

SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=)

all: $(OBJS)

test: all	
	./main
	./0-2
	./0-4
	./0-9
	make clean

.PHONY: clean
clean:
	rm -f $(OBJS) *.o
