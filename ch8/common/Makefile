CXX = g++

CXXFLAGS = -Wall -O2

Target = grade.o Student_info.o

all: $(Target)


grade.o: median.h Student_info.h grade.h grade.cpp 
	$(CXX) $(CXXFLAGS) -c grade.cpp

Student_info.o:Student_info.h Student_info.cpp
	$(CXX) $(CXXFLAGS) -c Student_info.cpp


.PHONY: clean
clean:
	rm -f *.o 
