CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 #-g -fsanitize=address
TARGET := build/program

SOURCES := driver.cpp
HEADERS := bstree.hpp algorithms.hpp

OBJECTS := $(SOURCES:%.cpp=build/%.o)

$(TARGET): $(OBJECTS)
	@$(CXX) $(OBJECTS) -o $(TARGET)

build/%.o: %.cpp $(HEADERS) | build
	@$(CXX) $(CXXFLAGS) -c $< -o $@

build:
	@mkdir -p build

clean:
	@rm -rf build

.PHONY: clean
