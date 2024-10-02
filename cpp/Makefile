# Define the source directory
VPATH = src

# Define the object file directory
OBJDIR = obj

# Define the executable file directory
BINDIR = bin

# Define the compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Define the source files
SOURCES = jdn.cpp

# Define the object files
OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS := $(addprefix $(OBJDIR)/, $(OBJECTS))

# Define the executable
EXECUTABLE = jdn
EXECUTABLE := $(BINDIR)/$(EXECUTABLE)

# Default target
all: $(EXECUTABLE)

# Create the obj directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Create the bin directory if it doesn't exist
$(BINDIR):
	mkdir -p $(BINDIR)

# Rule for building the executable
$(EXECUTABLE): $(OBJECTS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for building object files
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)