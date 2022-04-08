CXX = g++
CC = g++
CXXFLAGS = -Wall -O2
SRC_DIR = ./src
OBJ_DIR = ./obj
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(SRCS:.cpp=.o)
 
PROGRAMS = 10-0 10-1 10-2 10-3 10-4 10-5 10-6
all: $(PROGRAMS)

OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))
PROGRAMS_SRC = $(PROGRAMS:=.cpp) 
PROGRAMS_OBJ = $(PROGRAMS:=.o) 
DEPS = $(PROGRAMS:=.d) 

test: all 
	./10-1 < ../data/ch10/students100.txt
	
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