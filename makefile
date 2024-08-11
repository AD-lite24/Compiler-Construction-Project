CC = gcc
CFLAGS = -Wall -Wextra -g

SRC_FILES = driver.c lexer.c parser.c
OBJ_FILES = $(SRC_FILES:.c=.o)
EXEC = output

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(EXEC)