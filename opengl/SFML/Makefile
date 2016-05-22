

CC=clang++
GL_OPTIONS=-lsfml-window -lsfml-system -lsfml-graphics
#GL_OPTIONS=-lGLEW -lglfw -lGL -lXmu -lX11 -lm
CFLAGS=-std=c++11 -Wall -c  -ggdb -O0 
LDFLAGS=$(GL_OPTIONS) 

SOURCES=HelloSFML.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=HelloSFML

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -rf *.o $(EXECUTABLE)

check:
	cppcheck --std=c++11 *.cpp

