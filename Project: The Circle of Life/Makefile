# Makefile for TCOL Game

# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Directories
SRC_DIR = CPP
HEADER_DIR = Headers
DATA_DIR = Data
OUTPUT_DIR = Data/Game\ Data

# Source and Object files
SRCS = GameDriver.cpp $(SRC_DIR)/Board.cpp $(SRC_DIR)/Character.cpp $(SRC_DIR)/Game.cpp $(SRC_DIR)/Player.cpp
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = TCOL

# Default rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(HEADER_DIR) -c $< -o $@

# Clean rule
clean:
	rm -f $(TARGET) $(OBJS)

# Run the game
run: $(TARGET)
	./$(TARGET)
