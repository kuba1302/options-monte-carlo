CC=g++
CFLAGS=-I include -I $(VCPKG_ROOT)/installed/arm64-osx/include -std=c++20 -Wall
LDFLAGS=-L $(VCPKG_ROOT)/installed/x64-linux/lib

TARGET=main

SRCDIR=src
OBJDIR=obj
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

$(shell mkdir -p $(OBJDIR))

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

.PHONY: all clean
