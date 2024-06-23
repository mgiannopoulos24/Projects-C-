# Compiler
CXX = g++

# Directories
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = build

# Flags
CXXFLAGS = -I$(INCLUDE_DIR) -std=c++11 -Wall

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Target executable
TARGET = $(BUILD_DIR)/dictionary_app

# Build target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build directory
clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)

# PHONY targets to avoid conflicts with files of the same name
.PHONY: all clean
