CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o social.o
TARGET = isen_media

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c social.h
	$(CC) $(CFLAGS) -c main.c

social.o: social.c social.h
	$(CC) $(CFLAGS) -c social.c

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean