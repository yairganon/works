#format is target-name: target dependencies
#{-tab-}actions

# All Targets
all: count-words

# Tool invocations
# Executable "ass_0" depends on the files main.o and myasm.o.
count-words: 
	gcc -m32 -g -Wall  -o bin/count-words count-words.c

#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean: 
	rm -f bin/*.o bin/count-words