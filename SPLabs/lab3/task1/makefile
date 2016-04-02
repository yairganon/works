#format is target-name: target dependencies
#{-tab-}actions

# All Targets
all: virusDetector

# Tool invocations
# Executable "ass_0" depends on the files main.o and myasm.o.
virusDetector: input/signatures
	gcc -m32 -g -Wall  -o bin/virusDetector src/virusDetector.c

#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean: 
	rm -f bin/*.o bin/virusDetector