SOURCE_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build
BIN_DIR=bin

CC=gcc
WINCC=i686-w64-mingw32-gcc

EXECUTABLES = main creator reporter
ALL = $(addprefix $(BIN_DIR)/, $(addsuffix .exe, $(EXECUTABLES)))

.PHONY: clean

all: $(ALL)

$(BIN_DIR)/%.exe: $(BUILD_DIR)/%.o | $(BIN_DIR)
	$(WINCC) $^ -o $@ -Wall

$(BIN_DIR)/main.exe: $(addprefix $(BUILD_DIR)/, main.o await.o cat.o) | $(BIN_DIR)
	$(WINCC) $^ -o $@ -Wall

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(WINCC) -c $< -o $@ -I$(INCLUDE_DIR) -Wall

$(BUILD_DIR):
	@mkdir $@

$(BIN_DIR):
	@mkdir $@

clean:
	@if [ -d $(BUILD_DIR) ]; then du -h -a $(BUILD_DIR); fi
	@rm -rf $(BUILD_DIR);
	@echo -----------
	@if [ -d $(BIN_DIR) ]; then du -h -a $(BIN_DIR); fi
	@rm -rf $(BIN_DIR);
	@echo -----------
	@echo Clean done.

