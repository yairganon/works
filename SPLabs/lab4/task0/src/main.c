#include "util.h"
#define SYS_EXIT 1
#define SYS_WRITE 4
#define SYS_OPEN 5
#define SYS_LSEEK 19
#define SYS_READ 3
#define SYS_CLOSE 6
#define SYS_WRITE 4
#define STDOUT 1
extern int system_call();
#define printStr(); system_call(SYS_WRITE,STDOUT, str,strlen(str));
#define printNewLine(); system_call(SYS_WRITE,STDOUT, "\n",1);
int main (int argc , char* argv[], char* envp[])
{
  char* str;
  char* fileName = argv[1];
  char* nameToReplace = argv[2];
  int filedesc,fileSize,i , lengthRead; 
  char* nameToFind = "Shira";
  if(argc!=3)
    system_call(SYS_EXIT,0x55);
  filedesc = system_call(SYS_OPEN,fileName, 2 , 0777);
  if(filedesc<0)
    system_call(1,0x55);
  fileSize=system_call(SYS_LSEEK ,filedesc , 0 ,2 );
  char buffer[fileSize];
  system_call(SYS_WRITE,STDOUT, "File Name: ",11);
  system_call(SYS_WRITE,STDOUT, fileName,strlen(fileName));
  printNewLine();
  system_call(SYS_WRITE,STDOUT, "Name To Change: ",16);
  system_call(SYS_WRITE,STDOUT, nameToReplace,strlen(nameToReplace));
  printNewLine();
  system_call(SYS_WRITE,STDOUT, "File Size: ",11);
  str = itoa(fileSize);
  printStr();
  system_call(SYS_WRITE,STDOUT, " bytes",6);
  printNewLine();
  system_call(SYS_LSEEK ,filedesc , 0 ,0 );
  lengthRead= system_call(SYS_READ,filedesc,&buffer,fileSize);
  if(lengthRead<0)
    system_call(1,0x55);
  printNewLine();
  str = buffer;
  for(i=0; i<fileSize ; i++){
    if(strncmp(str+i,nameToFind,5)==0){
      str = itoa(i);
      printStr();
      printNewLine();
      break;
    }
  }
  system_call(SYS_LSEEK ,filedesc , i ,0 );
  system_call(SYS_WRITE ,filedesc,nameToReplace,strlen(nameToReplace));
  system_call(SYS_CLOSE,filedesc);
  return 0;
}