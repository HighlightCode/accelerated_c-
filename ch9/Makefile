CXX = g++
CC = g++
CXXFLAGS = -Wall -O2
SRC_DIR = ./src
OBJ_DIR = ./obj
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(SRCS:.cpp=.o)
 
PROGRAMS = 9-0 9-1 9-3 9-4 9-5 9-6
all: $(PROGRAMS)

OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))
PROGRAMS_SRC = $(PROGRAMS:=.cpp) 
PROGRAMS_OBJ = $(PROGRAMS:=.o) 
DEPS = $(PROGRAMS:=.d) 

test: all 
	./9-0 < ../data/ch9/students100.txt
	./9-1 < ../data/ch9/students100.txt
	./9-3 < ../data/ch9/students100.txt
	./9-4 < ../data/ch9/students100_v2.txt
	./9-5 < ../data/ch9/students100.txt
	./9-6 < ../data/ch9/students100.txt
	
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -MD 

%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@  

$(PROGRAMS) : % : %.o $(OBJECTS) 
	$(CC) $(CXXFLAGS) $(OBJECTS) $< -o $@ $(LDFLAGS)

.PHONEY: claen all
clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET) $(PROGRAMS) $(PROGRAMS_OBJ)

-include $(DEPS)