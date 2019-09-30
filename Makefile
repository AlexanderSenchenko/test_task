BIN_NAME := main

SRC_PATH := src
BUILD_PATH := build
BIN_PATH := bin

SRC_EXT := cpp
CC := g++

SRC_FILES = $(wildcard $(addsuffix /*.$(SRC_EXT), $(SRC_PATH)))
OBJECTS := $(addprefix $(BUILD_PATH)/, $(notdir $(SRC_FILES:.$(SRC_EXT)=.o)))

all: dirs $(BIN_PATH)/$(BIN_NAME)

$(BIN_PATH)/$(BIN_NAME): $(OBJECTS)
	$(CC) $^ -o $@

VPATH := $(SRC_PATH)
$(BUILD_PATH)/%.o: %.$(SRC_EXT)
	$(CC) $< -c -o $@

.PHONY: dirs
dirs:
	@mkdir $(BUILD_PATH) -p
	@mkdir $(BIN_PATH) -p

.PHONY: clean
clean:
	@rm -rf $(BIN_PATH)
	@rm -rf $(BUILD_PATH)