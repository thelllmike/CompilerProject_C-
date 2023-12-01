# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall
INCLUDES = -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source and object files
SOURCE_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECT_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCE_FILES))

# Targets
TARGET = your_program_name

# Build rules
all: $(BUILD_DIR) $(TARGET)

$(TARGET): $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(TARGET)

.PHONY: all clean
