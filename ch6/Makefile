CXX = g++
CC = g++
CXXFLAGS = -Wall -O2
SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)
target = $(SRCS:.cpp=)

all: main palindrome 6-1 6-2 6-3 6-4 6-5 6-6 6-7 6-8 6-9

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $<


6-2.o: 6-2.cpp url.cpp

main: main.o student_info.o grade.o vec.o
6-1: 6-1.o
6-2: 6-2.o url.o
6-5: 6-5.o student_info.o grade.o vec.o
6-6: 6-6.o student_info.o grade.o vec.o
6-7: 6-7.o student_info.o grade.o vec.o
6-8: 6-8.o student_info.o grade.o vec.o

test: all 
	./main < ../data/ch6/students100.txt
	./palindrome < ../data/ch6/palindrome.txt
	./6-1 
	./6-2 
	./6-3 
	./6-4 
	./6-5 < ../data/ch6/students100.txt
	./6-6 < ../data/ch6/students100.txt
	./6-7 < ../data/ch6/students100.txt
	./6-8 < ../data/ch6/students100.txt
	./6-9

.PHONY: clean
clean:
	rm -f $(OBJS) main $(target)

include main.d