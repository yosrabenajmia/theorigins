CC = gcc
CFLAGS = -Wall -Wextra -I/usr/include/SDL -D_REENTRANT
LDFLAGS = -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf  # Added -lSDL_ttf

SRC = main.c menu.c
OBJ = $(SRC:.c=.o)
EXEC = game

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

%.o: %.c menu.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean

