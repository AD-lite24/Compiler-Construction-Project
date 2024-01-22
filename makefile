# Makefile

CC = gcc
CFLAGS = -Wall -I./include
LIBS = -lm

SRCDIR = src
TESTDIR = tests
OBJDIR = build
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/*.c)
TEST_SOURCES = $(wildcard $(TESTDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
TEST_OBJECTS = $(patsubst $(TESTDIR)/%.c, $(OBJDIR)/%.o, $(TEST_SOURCES))
EXECUTABLE = $(BINDIR)/my_program
TEST_EXECUTABLE = $(BINDIR)/test_suite

all: $(EXECUTABLE)

tests: $(TEST_EXECUTABLE)
    ./$(TEST_EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(CFLAGS) $^ -o $@

$(TEST_EXECUTABLE): $(TEST_OBJECTS) $(OBJECTS)
    $(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
    $(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(TESTDIR)/%.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJDIR)/*.o $(EXECUTABLE) $(TEST_EXECUTABLE)

.PHONY: tests
