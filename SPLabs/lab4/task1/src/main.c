#include "util.h"
#define STDIN 0
#define SYS_EXIT 1
#define STDOUT 1
#define STDERR 2
#define SYS_READ 3
#define SYS_WRITE 4
#define SYS_OPEN 5
#define SYS_CLOSE 6
#define SYS_LSEEK 19
extern int system_call();
void printSystemCallDebugMode(int returnCode,int mode,int debugMode,char* ch,int filterd);
int main (int argc , char* argv[], char* envp[])
{
  char ch;
  char *str;
  char *fileInputName;
  char *fileOutputName;
  int i,returCode;
  int isDebugModeOn=0;
  int input=STDIN,output=STDOUT;
  for(i=1 ; i<argc ; i++){
    if(strcmp(argv[i],"-d")==0)
      isDebugModeOn=1;
    if(strcmp(argv[i],"-o")==0){
      fileOutputName = argv[++i];
      output  = system_call(SYS_OPEN,fileOutputName, 64 | 2 , 0777);
      printSystemCallDebugMode(output,SYS_OPEN,isDebugModeOn,0,0);
      if(output<0){
        system_call(SYS_WRITE , STDERR , "Error create/open file" , 22); 
        system_call(SYS_WRITE , STDERR , "\n" , 1);
        system_call(1,0x55);
      }
    }
    if(strcmp(argv[i],"-i")==0){
      fileInputName = argv[++i];
      input = system_call(SYS_OPEN,fileInputName,2,0777);
      printSystemCallDebugMode(input,SYS_OPEN,isDebugModeOn,0,0);
      if(input<0){
        system_call(SYS_WRITE , STDERR , "Error open file" , 22); 
        system_call(SYS_WRITE , STDERR , "\n" , 1);
        system_call(1,0x55);
      }
    }
  }
  if(isDebugModeOn){                                                   /* DEBUG MODE*/
    for(i=1 ; i<argc  ; i++){
      system_call(SYS_WRITE , STDERR , "\t\t*argv[" , 8);                
      str = itoa(i);
      system_call(SYS_WRITE , STDERR , str , strlen(str));          
      system_call(SYS_WRITE , STDERR , "] = " , 4);                 
      system_call(SYS_WRITE , STDERR , argv[i] , strlen(argv[i]));  
      system_call(SYS_WRITE , STDERR , "*\n" , 2);                   
    }
    system_call(SYS_WRITE , STDERR , "\t\t*filterd: 'H','h'*" , 20);
    system_call(SYS_WRITE , STDERR , "\n" , 1);
    system_call(SYS_WRITE , STDERR , "\t\t*input: " , 10);
    if(input==STDIN)
      system_call(SYS_WRITE , STDERR , "stdin" , 5);
    else
      system_call(SYS_WRITE , STDERR , fileInputName , strlen(fileInputName));
    system_call(SYS_WRITE , STDERR , "*\n" , 2);
    system_call(SYS_WRITE , STDERR , "\t\t*output: " , 11);
    if(output==STDOUT)
      system_call(SYS_WRITE , STDERR , "stdout" , 6);
    else
      system_call(SYS_WRITE , STDERR , fileOutputName , strlen(fileOutputName));
    system_call(SYS_WRITE , STDERR , "*\n" , 2);

  }                                                                   /* DEBUG MODE*/

  while((returCode=system_call(SYS_READ , input , &ch , 1) )>0){
    if(ch!='h' && ch!='H'){
      printSystemCallDebugMode(returCode,input,isDebugModeOn,&ch,0);
      returCode=system_call(SYS_WRITE , output , &ch , 1);
      printSystemCallDebugMode(returCode,output,isDebugModeOn,0,0);
      }
    else
      printSystemCallDebugMode(returCode,input,isDebugModeOn,&ch,1);
    }
  printSystemCallDebugMode(returCode,input,isDebugModeOn,&ch,0);  
  if(output!=STDOUT){
    returCode=system_call(SYS_CLOSE , output ,0,0);  
    printSystemCallDebugMode(returCode,SYS_CLOSE,isDebugModeOn,0,0);
  }
  if(input!=STDIN){
    returCode=system_call(SYS_CLOSE , input ,0,0);  
    printSystemCallDebugMode(returCode,SYS_CLOSE,isDebugModeOn,0,0);
  }
  return 0;
  
}
void printSystemCallDebugMode(int returnCode,int mode,int debugMode,char* ch,int filterd){
  if(debugMode){
        char* str;
        system_call(SYS_WRITE , STDERR , "\t\t*System Call Mode: " , 20); 
        str = itoa(mode);
        system_call(SYS_WRITE , STDERR , str , strlen(str));    
        system_call(SYS_WRITE , STDERR , " return:" , 8);   
        str = itoa(returnCode); 
        system_call(SYS_WRITE , STDERR , str , strlen(str));   
        if(mode==STDIN){
          system_call(SYS_WRITE , STDERR , " -Input Read: '" , 15); 
          if(*ch=='\n')
            system_call(SYS_WRITE , STDERR , "\\n" , 2);
          else
            system_call(SYS_WRITE , STDERR , ch , 1);
          system_call(SYS_WRITE , STDERR , "'" , 1);
          if(filterd){
            system_call(SYS_WRITE , STDERR , " -filterd" , 9); 
          }
        }
        system_call(SYS_WRITE , STDERR , "*\n" , 2);

    }
}