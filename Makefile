# Compiler and Linker
CXX := g++

# The Target Binary Program
TARGET := build/CompilerProject

# Directories
SRCDIR := src
BUILDDIR := build
INCDIR := include

# Flags, Libraries and Includes
CXXFLAGS := -std=c++17 -Wall -I$(INCDIR)
LDFLAGS := 
LIB := 

# Code Lists
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Default Make
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS) $(LIB)

# Compile the object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Objects
clean:
	$(RM) -r $(BUILDDIR)

# Non-File Targets
.PHONY: all clean
