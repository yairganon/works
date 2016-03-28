#format is target-name: target dependencies
#{-tab-}actions

# All Targets
all: addresses

# Tool invocations
# Executable "ass_0" depends on the files main.o and myasm.o.
addresses: 
	gcc -m32 -g -Wall  -o bin/addresses src/addresses.c
	gcc -m32 -g -Wall  -o bin/task2 src/task2.c
	gcc -m32 -g -Wall  -o bin/task3 src/task3.c

#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean: 
	rm -f bin/*.o bin/addresses
