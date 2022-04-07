CXX = g++
CC = g++
CXXFLAGS = -Wall -O2
SRC_DIR = ./src
OBJ_DIR = ./obj
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(SRCS:.cpp=.o)
 
PROGRAMS = split_test 8-1 8-2 8-3 8-4 8-5 8-6
all: $(PROGRAMS)

OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))
PROGRAMS_SRC = $(PROGRAMS:=.cpp) 
PROGRAMS_OBJ = $(PROGRAMS:=.o) 
DEPS = $(PROGRAMS:=.d) 

pp :
	@echo DEPS: $(DEPS) 
	@echo PROGRAMS_OBJ: $(PROGRAMS_OBJ)
	@echo PROGRAMS_SRC: $(PROGRAMS_SRC)
	@echo DEPS: $(DEPS)

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