CXX = g++

CXXFLAGS = -Wall -O2

SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=)

all: $(OBJS)

test:		all
	./greet <../data/name1
	./frame <../data/name2
	./main < ../data/name1
	make clean

	
.PHONY: clean
clean:
	rm -f $(OBJS) *.o
