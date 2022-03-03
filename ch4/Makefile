CXX = g++
CC = g++
CXXFLAGS = -Wall -O2
SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=)


Student_info.o:	Student_info.cpp Student_info.h
grade.o: grade.cpp grade.h median.h Student_info.h
main.o: main.cpp Student_info.h median.h grade.h
4-6.o: 4-6.cpp Student_info.h median.h grade.h
median.o: median.cpp median.h

main: main.o grade.o median.o Student_info.o
4-6: 4-6.o grade.o median.o Student_info.o

all: main 4-2 4-3 4-4 4-5 4-6 4-7
 
test: all
	./main < ../data/ch4/grades
	./4-2
	./4-3 < ../data/ch4/4-3
	./4-4 < ../data/ch4/4-4
	./4-5 < ../data/ch4/4-5
	./4-6 < ../data/ch4/grades
	./4-7 < ../data/ch4/4-7

.PHONY:
	clean

clean:
	rm -f *.o $(OBJS)

