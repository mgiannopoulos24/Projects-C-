# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Directories
SRCDIR = src
BUILDDIR = build
INCLUDEDIR = include
OBJDIR = obj

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
# Object files
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
# Executable name
EXEC = $(BUILDDIR)/contact_manager

# Default target
all: $(EXEC)

# Linking step
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

# Compilation step for .cpp files to .o object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Clean up object files and executable
clean:
	rm -rf $(OBJDIR) $(EXEC)

.PHONY: all clean
