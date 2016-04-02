#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIGNATURES "input/signatures"
typedef struct {
    unsigned short length;
    char name[16];
    char signature[];
}virus;
typedef struct link link;
struct link {
    virus *v;
    link *next;
};
FILE* virusFile;
virus* newVirus(int length,char* name ,char* signature);
link* list_append(link* virus_list, virus* data);
void list_print(link *virus_list); 
void list_free(link *virus_list);
void PrintHex(char* buffer,size_t length);
void bigToLittle(unsigned int* length);
void detect_virus(char *buffer, link *virus_list, unsigned int size);

int main(int argc, char **argv) {
	unsigned int* length = (unsigned int*)malloc(sizeof(unsigned int));
	char* signature=(char*) malloc(sizeof(char)*1);
	char* name= 	(char*) malloc(sizeof(char)*16);
	char* buffer=	(char*) malloc(sizeof(char)*10000);
	link* virus_list =NULL;
	virus* data;
	unsigned int scanFileSize;
	FILE* fp = fopen(SIGNATURES,"r");

    if(fp==NULL){
        perror(SIGNATURES);
        return -1;
    }
    while(fread(length,2,1,fp)>0){
	    bigToLittle(length);
	    fread(name,1,16,fp);
	    *length-=18;
	    signature = (char*) realloc(signature,sizeof(char)*(*length));
	    fread(signature,1,*length,fp);
	    data = newVirus(*length,name ,signature);
	    virus_list = list_append(virus_list,data);

}
	//list_print(virus_list);
	virusFile = fopen("input/signatures","r+");
	scanFileSize=fread(buffer,1,10000,virusFile);
	detect_virus(buffer,virus_list, scanFileSize);
	list_free(virus_list);
	fclose(virusFile);
	fclose(fp);
	free(buffer);
	free(signature);
	free(length);
	free(name);
	return 0;
}
void bigToLittle(unsigned int* length){
	char* x1 = (char*)length;
    char temp = *x1;
    *(x1)=*(x1+1);
    *(x1+1) = temp;
}
link* list_append(link* virus_list, virus* data){
	link* current = virus_list;
	link* newLink= (link*) malloc(sizeof(link));
	newLink->next=NULL;
	newLink->v=data;
	if(current==NULL){
		current =newLink;
		return current;
	}
	while(current->next!=NULL)
		current=current->next;
	current->next=newLink;
	return virus_list;
}
void list_print(link *virus_list){
	link* current = virus_list;
	while(current!=NULL){
		printf("Virus next:%s\n",current->v->name);
		printf("Virus length: %i\n", current->v->length);
		printf("signature: \n");
		PrintHex(current->v->signature, current->v->length);
		current=current->next;
	}
}
void list_free(link *virus_list){
	link *curr ;
	while((curr=virus_list) != NULL){
		free(virus_list->v);
		virus_list = virus_list->next;
		free(curr);
	}
}
void PrintHex(char* buffer,size_t length){
    int i;
    for(i=0 ;i<length;i++){
    	if(i%16 ==0 && i>0) printf("\n");
        printf("%02hhX ",buffer[i]);
    }
    printf("\n\n");
}
virus* newVirus(int length,char* name ,char* signature){
	virus* data = (virus*) malloc(sizeof(unsigned short)+sizeof(char)*16+sizeof(char)*(length));
	int i;
	data->length=length;
	for(i =0 ; i<16 ; i++)
		data->name[i]=*(name+i);
	for(i =0 ; i<length ; i++)
	   	data->signature[i]=*(signature+i);
	return data;
}
void detect_virus(char *buffer, link *virus_list, unsigned int size){
	int i,k;
	link *current;
	char *repalceNOP;
	for(i=0;i<size;i++){
		current=virus_list;
		while(current!=NULL){
			if(memcmp((buffer+i),current->v->signature,current->v->length)==0){
				printf("****virus****\n");
				printf("line: %i\n",i);
				printf("Virus name: %s\n",current->v->name);
				printf("Virus signature size: %i\n",current->v->length);
				printf("In Byte: %X\n",i);
				printf("****virus****\n");
				printf("****Clean Virus****\n");
				fseek(virusFile,i,SEEK_SET);
				repalceNOP = (char*)malloc(sizeof(char)*(current->v->length));
				for(k=0;k<(current->v->length);k++){
					*(repalceNOP+k)=0x90;
					printf("*");
				}
				fwrite(repalceNOP,1,current->v->length,virusFile);
				printf("\n****Virus Removed****\n");
				free(repalceNOP);
			}
			current=current->next;
		}
	}
}

