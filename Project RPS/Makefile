# Define the compiler and the flags
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

# Define the directories
SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = build
INCLUDE_DIR = include

# Define the target executable
TARGET = $(BUILD_DIR)/rock_paper_scissors

# Define the source files and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Default target to build the executable
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile the source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the obj directory if it does not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to clean up the build files
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Phony targets to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean
