CC := gcc
CCFLAGS := -lSDL -lm

SRCDIRS := src
SOURCES := $(foreach DIR, $(SRCDIRS), $(wildcard $(DIR)/*.c))
TARGET := bin/PrettyPatterns

.PHONY: all
.PHONY: clean

all: $(TARGET)

clean:
	rm -f $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) -o $(TARGET) $(SOURCES) $(CCFLAGS)
