CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
TARGET = campus_guard

# Find all .cpp files in the current directory
SRCS = $(wildcard *.cpp)

# Convert .cpp filenames to .o (object) filenames
OBJS = $(SRCS:.cpp=.o)

# Default target built when you just type 'make'
all: $(TARGET)

# Link all the object files to create the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each .cpp file into a .o object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files so you can start fresh
clean:
	rm -f $(OBJS) $(TARGET)

# Convenience target to build and run the program immediately
run: $(TARGET)
	./$(TARGET)