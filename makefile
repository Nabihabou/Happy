CC 					= g++
SOURCES 		= src/main.cpp src/BinaryExpressionTree.cpp src/utils.cpp
FLAGS 			= -std=c++14 -Wall -lreadline
OBJECTS 		= $(SOURCES:.cpp=.o)
EXEC				= Interpreter
all:
	$(CC) $(FLAGS) $(SOURCES) -o $(EXEC)

main:
	$(CC) $(FLAGS) src/main.cpp -o $(EXEC)
