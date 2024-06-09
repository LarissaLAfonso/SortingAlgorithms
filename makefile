# Makefile to compile all cpp files in a directory and subdirectories into a single executable

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Output executable name
TARGET = out

# Source files
SRCS = $(shell find . -name '*.cpp')

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

# Clean up
clean:
	rm -f $(TARGET)

.PHONY: all clean
