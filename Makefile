CXX = g++

CXXFLAGS = -Wall -O2
SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=)

all: main main4-1 main4-2 subsystem

subsystem:
	cd main4-3; $(MAKE)

test:	all
	./main4-1 <./data/single_grade
	./main4-2 <./data/single_grade
	cd main4-3; ./main4-3 <../data/grades

clobber:
	rm -f *.o *.exe core main1 main2 