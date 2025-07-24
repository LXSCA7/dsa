CC = gcc
TARGET = bin/main
SRCS = main.c linked_list.c stack.c queue.c

all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p bin
	$(CC) $(SRCS) -o $(TARGET)
	@echo "Success. Check bin folder"

run: all
	./$(TARGET)

clean:
	@rm -rf bin
	@echo "Deleted build files."

.PHONY: all run clean