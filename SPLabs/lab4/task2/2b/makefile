
all: task0


task0: bin/start.o bin/util.o bin/main.o 
	ld -melf_i386 bin/start.o bin/main.o bin/util.o -o bin/task0

bin/start.o: src/start.s
	nasm -f elf src/start.s -o bin/start.o
bin/util.o: src/util.c
	gcc -m32 -Wall -ansi -c -nostdlib -fno-stack-protector src/util.c -o bin/util.o
bin/main.o: src/main.c
	gcc -m32 -Wall -ansi -c -nostdlib -fno-stack-protector src/main.c -o bin/main.o
.PHONY: clean
clean: 
	rm -f bin/*.o bin/task0