PREFIX := /usr/local

CPPFLAGS := -I./include

CPPFLAGS += -std=c++11 -Wall -Wextra -pedantic

LFLAGS := -lX11 -lglfw -lGL -lGLEW -lm -lstdc++

SOURCES = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
TESTS = $(wildcard tests/*.cpp) $(wildcard tests/**/*.cpp)
OBJECTS = $(subst .cpp,.o,$(SOURCES))
TEST_OBJS = $(subst .cpp,.o,$(TESTS))

.PHONY: all
all: nautical

nautical: $(OBJECTS)
	test -d bin/ || mkdir -p bin/
	$(CC) $(CPPFLAGS) $(OBJECTS) $(LFLAGS) -o bin/nautical

test: $(TEST_OBJS)
	$(CC) $(CPPFLAGS) -I./tests -o bin/nautical-tests $(TEST_OBJS) $(LFLAGS) -lcunit
	./bin/nautical-tests

clean:
	@for dir in src; do find $$dir -name \*.o -exec rm -f {} \; ; done
	@for dir in tests; do find $$dir -name \*.o -exec rm -f {} \; ; done
	rm -f bin/nautical
