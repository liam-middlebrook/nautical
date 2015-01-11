PREFIX := /usr/local

CPPFLAGS := -I./include

CPPFLAGS += -std=c++11 -Wall -Wextra -pedantic

LFLAGS := -lX11 -lglfw -lGL -lGLEW -lm

SOURCES = $(wildcard src/*.cpp)
HEADERS = $(wildcard include/**.h)
OBJECTS = $(patsubst src/%.cpp,src/%.o,$(wildcard src/*.cpp))


.PHONY: all
all: nautical

nautical: $(OBJECTS)
	test -d bin/ || mkdir -p bin/
	$(CC) $(CPPFLAGS) $(OBJECTS) $(LFLAGS) -o bin/nautical

clean:
	@for dir in src; do find $$dir -name \*.o -exec rm -f {} \; ; done
	rm -f bin/nautical
