CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17
TARGET := build/program

SOURCES := tester.cpp
HEADERS := algorithms.hpp

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
