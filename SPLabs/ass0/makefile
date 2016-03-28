#format is target-name: target dependencies
#{-tab-}actions

# All Targets
all: ass_0

# Tool invocations
# Executable "ass_0" depends on the files main.o and myasm.o.
ass_0: bin/main.o
	gcc -m32 -g -Wall -o bin/ass_0 bin/main.o bin/myasm.o


	
# Depends on the source and header files
bin/main.o: bin/myasm.o src/C/main.c 
	gcc -g -Wall -m32  -c -o bin/main.o src/C/main.c 

bin/myasm.o: src/Assembly/myasm.s
	nasm  -g -f elf -w+all -o bin/myasm.o src/Assembly/myasm.s


#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean: 
	rm -f bin/*.o bin/ass_0