BIN_NAME := test

SRC_PATH := src
STATE_PATH := $(SRC_PATH)/state
BUILD_PATH := build
BIN_PATH := bin

SRC_EXT := cpp
CC := g++
COMPILE_FLAGS := -std=c++11 -g

SRC_FILES := $(SRC_PATH) $(STATE_PATH)
SRC_FILES := $(wildcard $(addsuffix /*.$(SRC_EXT), $(SRC_FILES)))
OBJECTS := $(addprefix $(BUILD_PATH)/, $(notdir $(SRC_FILES:.$(SRC_EXT)=.o)))

.PHONY: dirs clean

all: dirs $(BIN_PATH)/$(BIN_NAME)

$(BIN_PATH)/$(BIN_NAME): $(OBJECTS)
	$(CC) $(COMPILE_FLAGS) $^ -o $@

VPATH := $(SRC_PATH) $(STATE_PATH)
$(BUILD_PATH)/%.o: %.$(SRC_EXT)
	$(CC) $(COMPILE_FLAGS) $< -c -o $@

dirs:
	@mkdir $(BUILD_PATH) -p
	@mkdir $(BIN_PATH) -p

clean:
	@rm -rf $(BIN_PATH)
	@rm -rf $(BUILD_PATH)
