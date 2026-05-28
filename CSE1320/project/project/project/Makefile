PROJECT_NAME := project

SRC_DIR := source
UTILS_DIR := util
BUILD_DIR := build

RELEASE := $(BUILD_DIR)/$(PROJECT_NAME)

PROJECT_FILES := $(wildcard $(SRC_DIR)/*.c)
UTILS_FILES := $(wildcard $(SRC_DIR)/$(UTILS_DIR)/*.c)

project: $(PROJECT_FILES) $(UTILS_FILES)
	mkdir $(BUILD_DIR)
	gcc $(PROJECT_FILES) $(UTILS_FILES) -o $(RELEASE)
