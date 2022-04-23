CXX = g++
CC = g++
CXXFLAGS = -Wall -O2
SRC_DIR = ./src
OBJ_DIR = ./obj
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(SRCS:.cpp=.o)
 
PROGRAMS = 12-0 12-1 12-2 12-3 12-4 12-5 12-6 12-7 12-8 12-9 12-10 12-12 12-13 12-14
all: $(PROGRAMS)

OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))
PROGRAMS_SRC = $(PROGRAMS:=.cpp) 
PROGRAMS_OBJ = $(PROGRAMS:=.o) 
DEPS = $(PROGRAMS:=.d) 

test: all 
	
	
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