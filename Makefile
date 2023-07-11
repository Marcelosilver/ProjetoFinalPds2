CC = g++
CFLAGS = -std=c++17 -Wall

SRCDIR = src
OBJDIR = obj
BINDIR = bin
TESTDIR = test

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
TEST_SOURCES = $(wildcard $(TESTDIR)/*.cpp)
TEST_OBJECTS = $(patsubst $(TESTDIR)/%.cpp, $(OBJDIR)/%.o, $(TEST_SOURCES))

EXECUTABLE = $(BINDIR)/blackjack
TEST_EXECUTABLE = $(BINDIR)/test_blackjack

.PHONY: all clean run test

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) | directories
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)

clean:
	@rm -rf $(OBJDIR)/*.o $(EXECUTABLE) $(TEST_EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(OBJECTS) $(TEST_OBJECTS) | directories
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
