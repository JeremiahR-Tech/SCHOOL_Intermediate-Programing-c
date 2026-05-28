PROJECT_NAME := Assignment7

SRC_DIR := src
UTILS_DIR := utils
BUILD_DIR := build

RELEASE := $(BUILD_DIR)/$(PROJECT_NAME)

PROJECT_FILES := $(wildcard $(SRC_DIR)/*.c)
UTILS_FILES := $(wildcard $(SRC_DIR)/$(UTILS_DIR)/*.c)

project: $(PROJECT_FILES) $(UTILS_FILES)
	mkdir $(BUILD_DIR)
	gcc problem.c $(PROJECT_FILES) $(UTILS_FILES) -Wall -lm -o $(RELEASE)
debug: $(PROJECT_FILES) $(UTILS_FILES)
	mkdir $(BUILD_DIR)
	gcc problem.c $(PROJECT_FILES) $(UTILS_FILES) -Wall -lm -DDEBUG -o $(RELEASE)
clean:
	rm -rf $(BUILD_DIR)
