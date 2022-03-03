CXX = g++
CC = g++
CXXFLAGS = -Wall -O2
SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

all: main

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $<

main: $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o main

test: 
	./main
	

.PHONY: clean
clean:
	rm -f $(OBJS) main

include main.d