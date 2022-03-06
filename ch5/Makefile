CXX = g++
CC = g++
CXXFLAGS = -Wall -O2
SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)
target = $(SRCS:.cpp=)

all: main 5-2

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $<

5-2.o: 5-2.cpp grade.h Student_info.h
5-3.o: 5-3.cpp grade.h Student_info.h
5-4.o: 5-4.cpp grade.h Student_info.h
5-5.o: 5-5.cpp grade.h Student_info.h
5-6.o: 5-6.cpp grade.h Student_info.h
5-7.o: 5-7.cpp frame.h
5-8.o: 5-8.cpp frame.h
5-9.o: 5-9.cpp
5-10.o: 5-10.cpp

main: main.o frame.o split.o
5-2: 5-2.o grade.o median.o Student_info.o
5-3: 5-3.o grade.o median.o Student_info.o
5-4: 5-4.o grade.o median.o Student_info.o
5-5: 5-5.o frame.o split.o
5-6: 5-6.o grade.o median.o Student_info.o
5-7: 5-7.o frame.o
5-8: 5-8.o frame.o
5-9: 5-9.o
5-10: 5-10.o

test: all 
	./main
	./5-2
	./5-3
	./5-4
	./5-5
	./5-6
	./5-7
	./5-8
	./5-9
	./5-10
	./5-11

.PHONY: clean
clean:
	rm -f $(OBJS) main $(target)

include main.d