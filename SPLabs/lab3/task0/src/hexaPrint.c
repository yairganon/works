#include <stdio.h>
#include <stdlib.h>

void PrintHex(char* buffer,size_t length);
int main(int argc, char **argv) {
    FILE* fileName;
    size_t length;
    char* buffer ;
    if(argc<2 || argc>2){
        perror("hexaPrint [FileName]");
        return -1;
    }
    fileName = fopen(argv[1],"r");
    if(fileName==NULL){
        perror(argv[1]);
        return -1;
    }
    buffer = (char*)malloc(sizeof(char)*50);
    length=fread(buffer ,1, 50 ,fileName);
    PrintHex(buffer,length);
    free(buffer);
    fclose(fileName);
    return 0;
}
void PrintHex(char* buffer,size_t length){
    int i;
    for(i=0 ;i<length;i++)
        printf(" %0X ",buffer[i]);
    printf("\n");
}