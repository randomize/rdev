# 
# ddc-bright

CC=clang
CFLAGS=-c -Wall -Wextra -Wpedantic
INCLUDES=-I . \
		 -I /usr/include/ddccontrol \
		 -I /usr/include/libxml2 \
		 -I/usr/include/dbus-1.0 \
		 -I/usr/lib/dbus-1.0/include \
		 -I/usr/include/glib-2.0 \
		 -I/usr/lib/glib-2.0/include
	
LDFLAGS=-lddccontrol -ldbus-glib-1 -ldbus-1 -lgobject-2.0 -lglib-2.0
SOURCES=dbus.c
OBJECTS=$(SOURCES:.c=.o)

EXECUTABLE=dbus-listen


all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@



clean:
	rm -rf *.o $(EXECUTABLE)
