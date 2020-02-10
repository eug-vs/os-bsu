SOURCE_DIR=src
BUILD_DIR=build
CC=gcc
WINCC=i686-w64-mingw32-gcc

ALL = $(addsuffix .exe, $(basename $(addprefix $(BUILD_DIR)/, $(notdir $(wildcard src/*.c)))))

.PHONY: clean
.PRECIOUS: $(BUILD_DIR)/%.test

all: $(ALL)

$(BUILD_DIR)/%: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(CC) $< -o $@ -Wall

$(BUILD_DIR)/%.exe: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(WINCC) $< -o $@ -Wall

$(BUILD_DIR):
	@mkdir $@

clean:
	@if [ -d $(BUILD_DIR) ]; then du -h -a $(BUILD_DIR); fi
	@rm -rf $(BUILD_DIR);
	@echo Clean done.

