

CC=clang++
GL_OPTIONS=-lGLEW -lglfw -lGL -lXmu -lX11 -lm
CFLAGS=-std=c++11 -Wall -c  -ggdb -O0  -I/usr/include/GLFW -stdlib=libc++
LDFLAGS=$(GL_OPTIONS) 

SOURCES=HelloGLFW.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=HelloGLFW

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -rf *.o $(EXECUTABLE)

check:
	cppcheck --std=c++11 *.cpp

