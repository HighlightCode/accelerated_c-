CXX = g++

CXXFLAGS = -Wall -O2

OBJS = analysis.o main.o
COMMON_DIR = ../common

TARGET = main

all: subsystem $(TARGET)

subsystem: 
	cd ../common; $(MAKE)

SRCS = $(wildcard $(COMMON_DIR)/*.cpp)
HEAD_SRCS = $(SRCS:.cc=.h)
OBJ_SRCS = $(SRCS:.cc=o)

analysis.o: analysis.cpp analysis.h $(HEAD_SRCS)
	$(CXX) $(CXXFLAGS) -c $<
	@echo $(HEAD_SRCS)

main.o: main.cpp analysis.h $(HEAD_SRCS)
	$(CXX) $(CXXFLAGS) -c $<
	@echo $(OBJ_SRCS)

main: $(OBJS) $(OBJ_SRCS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(OBJ_SRCS) -o main

test: all
	@echo "\n\n\n############## 8-1 START ##############"
	./main < ../data/grades
	@echo "############## 8-1 FINISH ##############\n\n\n"
	make clean

.PHONY: clean
clean: 
	rm -f $(OBJS) main
	cd ../common; rm -f *.o
