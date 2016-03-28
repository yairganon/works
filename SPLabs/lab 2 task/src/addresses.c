#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int addr5;
int addr6;

int foo();
void point_at(void *p);
void print_array();
void print_array2();
int main (int argc, char** argv){
    int addr2;                          //stack
    int addr3;                          //stack
    char* yos="ree";                    //
    int * addr4 = (int*)(malloc(50));
    printf("stack- &addr2: %p\n",&addr2);
    printf("stack- &addr3: %p\n",&addr3);
    printf("stack- &addr4: %p\n",&addr4);
    printf("heap- addr4: %p\n",addr4);
    printf(".bss-- &addr6: %p\n",&addr6);
    printf(".bss-- &addr5: %p\n",&addr5);
	point_at(&addr5);  
    printf(".rodata- yos: %p\n",yos);
    printf(".text- foo: %p\n",foo);
    printf(".text- point_at: %p\n",point_at);
    print_array();
    print_array2();
    return 0;
}

int foo(){
    return -1;
}

void point_at(void *p){
    int local;
	static int addr0 = 2;
    static int addr1;
    printf(".bss- addr1: %p\n",&addr1);
    printf(".data - addr0: %p\n", & addr0);
    long dist1 = (size_t)&addr6 - (size_t)p;
    long dist2 = (size_t)&local - (size_t)p;
    long dist3 = (size_t)&foo - (size_t)p;
    
    printf("dist1: (size_t)&addr6 - (size_t)p: %ld\n",dist1);
    printf("dist2: (size_t)&local - (size_t)p: %ld\n",dist2);
    printf("dist3: (size_t)&foo - (size_t)p:  %ld\n",dist3);	
}
void print_array(){
    int iarray[3];
    char carray[3];
    printf("sizeof(int): %i\n",sizeof(int));
    printf("sizeof(char): %i\n",sizeof(char));
    printf("stack- &iarray 0: %p\n",(iarray+0));
    printf("stack- &iarray 1: %p\n",(iarray+1));
    printf("stack- &iarray 2: %p\n",(iarray+2));
    printf("stack- &carray 0: %p\n",(carray+0));
    printf("stack- &carray 1: %p\n",(carray+1));
    printf("stack- &carray 2: %p\n",(carray+2));    
}
void print_array2(){
    int iarray[] = {1,2,3};
    char carray[] = {'a','b','c'};
    int* iarrayPtr = &iarray[0];
    char* carrayPtr = &carray[0];
    //int* p;    
    //printf("stack- &iarray 0: %i\n",(p+0));
    printf("stack- &iarray 0: %i\n",*(iarrayPtr+0));
    printf("stack- &iarray 1: %i\n",*(iarrayPtr+1));
    printf("stack- &iarray 2: %i\n",*(iarrayPtr+2));
    printf("stack- &carray 0: %c\n",*(carrayPtr+0));
    printf("stack- &carray 1: %c\n",*(carrayPtr+1));
    printf("stack- &carray 2: %c\n",*(carrayPtr+2));    
}
