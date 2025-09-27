# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Werror -I.

# The final executable name
TARGET = sll_program

# The source files
SOURCES = sll.c sll_main.c

# Default rule to build the target
all: $(TARGET)

$(TARGET): $(SOURCES)
    $(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Rule to run the program
run: $(TARGET)
    ./$(TARGET)

# Rule to clean up compiled files
clean:
    rm -f $(TARGET)
