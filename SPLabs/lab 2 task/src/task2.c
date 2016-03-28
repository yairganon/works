#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int abs(int n); /* Gets an integer n, and returns the absolute value of n. */
int iprt(int n); /* Prints the value of n followed by a new line, and returns n unchanged */
int cprt(int n); /* Prints the character of ASCII value n followed by a new line, and returns n unchanged. 
                    If n is not between 0x20 and 0x7E, print the dot ('.') character instead. */
int my_get(int n); /* Ignores n, reads a line from stdin, and returns a number given in that line.  */
int plus_one(int n);
int quit(int n);
typedef struct{
  char *name;
  int (*fun)(int);
}fun_desc;
int* map(int *array, int arrayLength, int (*f) (int)){
  int* mappedArray = (int*)(malloc(arrayLength*sizeof(int)));
  int i;  	
  for(i=0 ; i<arrayLength ; i++)
  	*(mappedArray+i)=f(*(array+i));
  return mappedArray;
}
 
int main(int argc, char **argv){
	int i=0;
	int getOp;
	int len = 4;
	int *iarray;
	fun_desc funArray[] = {
		{.name = "Plus One" , .fun=plus_one},
		{.name = "Abs" , .fun=abs},
		{.name = "Print Integer" , .fun=iprt},
		{.name = "Print Character" , .fun=cprt},
		{.name = "Get numbers" , .fun=my_get},
		{.name = "Quit" , .fun=quit},
		//{.name = "Junk" , .fun=funArray},
		{.name = NULL , .fun=NULL}
	};
	while(1){
		i=0;
		while(funArray[i].name!=NULL && funArray[i].fun!=NULL){
			printf("%i) %s\n",i,funArray[i].name);
			i++;
		}
		printf("Option: ");
		getOp = my_get(0);
		if(getOp>=0 && getOp<=i){
			printf("within bounds\n");
			iarray = map(iarray , len , funArray[getOp].fun);
			printf("DONE.\n");
		}
		else{
			printf("not within bounds\n");
			return 0;
		}
	}

	// int* arr2 = map(iarray, len, my_get);
	// int* arr3 = map(arr2, len, abs);
	// int* arr4 = map(arr3, len, iprt);
	// int* arr5 = map(arr4, len, plus_one);
	// int* arr6 = map(arr5, len, cprt);
	// free(arr2);
	// free(arr3);
	// free(arr4);
	// free(arr5);
	// free(arr6);
	return 0;
}
int plus_one(int n) {return n+1;}
int abs(int n){return (n>0) ? n : n*-1;}
int my_get(int n){
	char buffer[50];
	fgets( buffer, 50, stdin );
	return atoi(buffer);
}
int iprt(int n){
	printf("%i\n",n);
	return n;
}
int cprt(int n){
	if(n>= 0x20 && n<= 0x7E)
		printf("%c\n",(char)n);
	else
		printf(".\n");
	return n;
}
int quit(int n){
	exit(n);
}