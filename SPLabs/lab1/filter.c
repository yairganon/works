#include <stdio.h>
typedef int bool;
#define true 1
#define false 0
int main(int argc, char *argv[]) {
	int c,j,filterLength=0 ,currentChar;
	bool flag=true;
	char *filter;
	FILE* input = stdin;
	FILE* output = stdout;
	while(argc>1 && argv[1][filterLength]!=0){
		c=argv[1][filterLength];
		argv[1][filterLength] = (c>96&&c<123)? (c-32) : c;
		filterLength++;
		flag=false;
	}
	if(flag){
		filter = "H";
		filterLength=1;
	}
	else
		filter = argv[1];
	while((c=fgetc(input))!=EOF){
		flag = true;
		currentChar = (c>96&&c<123)? (c-32) : c;
		for(j=0 ; j<filterLength && flag; j++)
			if(filter[j]==currentChar)
				flag=false;
		if(flag)
			putc(c, output);
		}
	return 0;
}