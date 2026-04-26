# Hvb generic makefile

CXX = g++
CXXSTD = -std=c++17

FLAGS = $(CXXSTD) -pedantic -Wall -g -O3 #-DDEBUG
LIBS = -llapack -lblas -lm 

OBJECTS = inventory_1.o

objects: $(OBJECTS)

%.o: %.cc
	$(CXX) -c $< $(FLAGS) -o $@

x%: x%.o objects
	$(CXX) $(FLAGS) -o $@ $< $(OBJECTS)  $(LIBS)
	./$@

clean:
	ls x* | grep -v "\." | xargs rm -f
	rm -f *.o 

mrproper:
	rm -f *.o 

