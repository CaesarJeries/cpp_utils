TOP=$(abspath .)

INCLUDE_DIR=.\
	    $()

CFLAGS = -Wall -ansi -pedantic -std=c++17 
CFLAGS += $(addprefix -iquote, $(INCLUDE_DIR))

ifndef debug
	CFLAGS += -DNDEBUG
endif

CC=g++

SOURCES=$(shell find $(TOP) -type f -iname '*.cpp' | grep -v test | grep -v main.cpp)
OBJECTS=$(foreach x, $(basename $(SOURCES)), $(x).o)

TEST_SOURCES=$(shell find $(TOP) -type f -iname '*_test.cpp')
TEST_BASENAMES=$(foreach x, $(basename $(TEST_SOURCES)), $(x))

DEPS=$(OBJECTS:%.o=%.d)

all:


%.o : %.c
	@# The -MMD flags additionaly creates a .d file with
	@# the same name as the .o file.
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@


%_test: %_test.cpp
	$(CC) $(CFLAGS) $^ $(OBJECTS) -o $@

test: $(OBJECTS) $(TEST_BASENAMES)
	echo "Building tests: $(TEST_BASENAMES)"


.PHONY: all clean test

clean:
	@rm -f *.tar
	@rm -f *.d
	@rm -f *_test
	@rm -f *.o
	@rm -f *.log
