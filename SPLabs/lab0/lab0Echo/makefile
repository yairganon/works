#format is target-name: target dependencies
#{-tab-}actions

# All Targets
all: filter

# Tool invocations
# Executable "hello" depends on the files hello.o and run.o.
add: 
	gcc -m32 -g -Wall -o filter filter.c

.PHONY: clean

#Clean the build directory
clean: 
	rm -f *.o filter
