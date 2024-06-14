# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11 -Wall
# Directories
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
# Headers
HEADERS := $(wildcard $(INCLUDE_DIR)/*.h)

# Executable name
EXEC := atm

# Default target
all: $(EXEC)

# Linking
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compiling
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

# Phony targets
.PHONY: all clean
