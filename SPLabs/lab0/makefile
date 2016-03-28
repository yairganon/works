#format is target-name: target dependencies
#{-tab-}actions

# All Targets
all: add

# Tool invocations
# Executable "hello" depends on the files hello.o and run.o.
add: numbers.o main.o add.o
	gcc -m32 -g -Wall -o add numbers.o main.o add.o

# Depends on the source and header files
numbers.o: numbers.c
	gcc -g -Wall -m32 -ansi -c -o numbers.o numbers.c 
	
# Depends on the source and header files
main.o: numbers.o main.c
	gcc -g -Wall -m32 -ansi -c -o main.o main.c 

add.o: main.o numbers.o add.s
	nasm  -g -f elf -w+all -o add.o add.s


#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean: 
	rm -f *.o add
