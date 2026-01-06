CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

SRC_DIR := src
OBJ_DIR := build
BIN := kvstore

SRC := $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/hashmap.cpp \
       $(SRC_DIR)/storage.cpp

OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN)

rebuild: clean all

.PHONY: all clean rebuild
