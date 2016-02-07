# 
# ddc-bright

CC=clang
CFLAGS=-c -Wall -Wextra -Wpedantic
INCLUDES=-I . \
		 -I /usr/include/ddccontrol \
		 -I /usr/include/libxml2
	
LDFLAGS=-lddccontrol
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)

EXECUTABLE=ddc-bright


all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@



clean:
	rm -rf *.o ddc-bright
