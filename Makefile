CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
# Your .hpp files
DEPS = EDistance.hpp
# Your compiled .o files
OBJECTS = EDistance.o
# The name of your program
PROGRAM = EDistance
TEST = test

.PHONY: all clean lint

all: $(PROGRAM) $(TEST) EDistance.a

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(TEST): test.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

EDistance.a: $(OBJECTS)
	ar rcs EDistance.a $(OBJECTS)

clean:
	rm *.o $(PROGRAM) $(TEST) EDistance.a

lint:
	cpplint *.cpp *.hpp