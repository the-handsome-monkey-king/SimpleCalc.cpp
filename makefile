# makefile
# 
# @author Ryan Morehouse
# @license MIT

OBJ = SimpleCalc.o test.o
DEPS = SimpleCalc.o
FLAGS = -Wall -lm
CC = g++
.SUFFIXES: .cpp .o

.cpp.o:
	g++ -o $@ $^ $(FLAGS)

all: $(OBJ)

SimpleCalc.o: SimpleCalc.cpp
	$(CC) -c -o $@ $< $(FLAGS)

test.o: test.cpp $(DEPS)

clean:
	\rm -f *.o
