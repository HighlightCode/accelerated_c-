CXX = g++

CXXFLAGS = -Wall -O2

OBJS = main.o

TARGET = main

main.o: main.cpp split.h
	$(CXX) $(CXXFLAGS) -c $<

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main

.PHONY: clean
clean:
	rm -f $(OBJS) main
