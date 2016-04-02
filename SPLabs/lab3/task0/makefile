#format is target-name: target dependencies
#{-tab-}actions

# All Targets
all: bubblesort

# Tool invocations
# Executable "ass_0" depends on the files main.o and myasm.o.
bubblesort: 
	gcc -m32 -g -Wall  -o bin/bubblesort src/bubblesort.c
	gcc -m32 -g -Wall  -o bin/hexaPrint src/hexaPrint.c

#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean: 
	rm -f bin/*.o bin/bubblesort