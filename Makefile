CC ?= gcc
CFLAGS ?= -Wall -Wextra -O2 -Isrc

SRCS := main.c $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)
TARGET := emu

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
