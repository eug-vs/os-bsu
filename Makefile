SOURCE_DIR=src
BUILD_DIR=build

.PHONY: clean
.PRECIOUS: $(BUILD_DIR)/%.test

all: $(BUILD_DIR)/main

$(BUILD_DIR)/%: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	gcc $< -o $@ -Wall

$(BUILD_DIR):
	@mkdir $@

clean:
	@if [ -d $(BUILD_DIR) ]; then du -h -a $(BUILD_DIR); fi
	@rm -rf $(BUILD_DIR);
	@echo Clean done.

