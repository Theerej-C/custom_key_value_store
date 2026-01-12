CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin

SERVER_BIN := server
CLIENT_BIN := client

COMMON_SRC := hashmap.cpp storage.cpp

SERVER_SRC := server.cpp $(COMMON_SRC)
CLIENT_SRC := client.cpp $(COMMON_SRC)

SERVER_OBJ := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SERVER_SRC))
CLIENT_OBJ := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(CLIENT_SRC))

all: $(SERVER_BIN) $(CLIENT_BIN)

$(SERVER_BIN): $(SERVER_OBJ)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$@ $^

$(CLIENT_BIN): $(CLIENT_OBJ)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

rebuild: clean all

.PHONY: all clean rebuild
