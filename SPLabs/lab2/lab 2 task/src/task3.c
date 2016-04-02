#include <stdio.h>
 #include <stdlib.h>
#include <stdbool.h>

#include <string.h>

int abs(int n); /* Gets an integer n, and returns the absolute value of n. */
int iprt(int n); /* Prints the value of n followed by a new line, and returns n unchanged */
int cprt(int n); /* Prints the character of ASCII value n followed by a new line, and returns n unchanged. 
                    If n is not between 0x20 and 0x7E, print the dot ('.') character instead. */
int my_get(int n); /* Ignores n, reads a line from stdin, and returns a number given in that line.  */
int quit(int n);
int plus_one(int n);


struct fun_desc {
  char *name;
  int (*fun)(int);
};
struct fun_desc menu[] = { { "plus one", plus_one }, { "abs", abs },{ "Print Integer", iprt},{ "Print Character", cprt},{ "Get numbers", my_get} , {"Quit", quit} , { NULL, NULL } };

int quit(int n){
	 exit(EXIT_FAILURE);
	 return n;
}
int plus_one(int n) {
  return n+1;
}
int abs(int n)/* Gets an integer n, and returns the absolute value of n. */
{
	int i= (-2);
	if(n<0) return(n+ (i*n));
	else return n;
}
int iprt(int n) /* Prints the value of n followed by a new line, and returns n unchanged */
{
	printf("%d\n", n );
	return n;
}
int cprt(int n) /* Prints the character of ASCII value n followed by a new line, and returns n unchanged. 
                 If n is not between 0x20 and 0x7E, print the dot ('.') character instead. */
{
	char c= n;
	if (33<n && n< 126)
		printf("%c\n",c );
	else
		printf(".\n");
	return n;

}
int my_get(int n) /* Ignores n, reads a line from stdin, and returns a number given in that line.  */
 {
 	
 	int i;
 	char input[50];
 	fflush(stdin);
 	 printf("insert a number :\n"); 	
fgets( input, 50, stdin );
     i = atoi(input);
     return i;

 }


int* map(int *array, int arrayLength, int (*f) (int)){
	int* mappedArray = (int*)(malloc(arrayLength*sizeof(int)));
	int i;
	for (i = 0; i < arrayLength; i++)
		{
		 mappedArray[i]= f(array[i]);
		}
	return mappedArray;
	}
	 
int main(int argc, char **argv){
	

    int a;
    int i;
	int *iarray;
	int len=4;

    while(true){
    printf("Please choose a function :\n");
    for (i = 0; i < 6; i++)
    {
    	printf("%d) %s\n",i,menu[i].name);
    }
    a = my_get(0);
    iarray = map(iarray, len, menu[a].fun);
}



}
