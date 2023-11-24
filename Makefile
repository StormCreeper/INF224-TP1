CC = g++
CFLAGS = -g -O1

TARGET := main.exe
OBJECTS := main.o ObjectGroup.o FilmObject.o DataManager.o tcpserver/ccsocket.o tcpserver/tcpserver.o
DEPS := FilmObject.h PhotoObject.h VideoObject.h ObjectGroup.h MultimediaObject.h DataManager.h

# Compiler options
LDFLAGS :=

LDLIBS := -lpthread -lws2_32

# Determine the operating system
ifeq ($(OS),Windows_NT)
    RM = del /Q
    EXECUTABLE_EXTENSION = .exe
else
    RM = rm -f
    EXECUTABLE_EXTENSION =
endif

# Compilation rules
all: $(TARGET)

$(TARGET): $(OBJECTS) $(DEPS)
	$(CC) -o $@ $(OBJECTS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

# Rule to compile C source files into object files
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean::
	$(RM) $(TARGET) $(OBJECTS)

run: $(TARGET)
	./$(TARGET)
