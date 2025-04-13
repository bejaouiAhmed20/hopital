CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Generate object file names from source files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
# Executable name
EXEC = $(BIN_DIR)/gestion_hopital

# Default target
all: directories $(EXEC)

# Create necessary directories for Windows
directories:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)

# Link object files to create executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean up generated files (Windows version)
clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)

# Run the program
run: all
	$(EXEC)

.PHONY: all directories clean run