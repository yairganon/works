#include <stdio.h>
# define MAX_LEN 100 				// Maximal line size
extern int add_Str_N (char*);
int main(void) {
	char str_buf[MAX_LEN];
	int count= 0;
	while(1){
	fgets(str_buf, MAX_LEN, stdin); // Read user's command line string
	count = add_Str_N (str_buf); 	// Your assembly code function
	printf("%s\n%d\n",str_buf,count);
}
	return 0;
}
