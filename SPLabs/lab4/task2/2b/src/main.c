#include "util.h"
#include <dirent.h>
#define STDIN 0
#define SYS_EXIT 1
#define STDOUT 1
#define STDERR 2
#define SYS_READ 3
#define SYS_WRITE 4
#define SYS_OPEN 5
#define SYS_CLOSE 6
#define DT_REG 8
#define SYS_LSEEK 19
#define SYS_GETDENTS 141
extern int system_call();
typedef struct ent
{
  int inode;
  int offset;
  short len;
  char buf[];
}ent;
int main (int argc , char* argv[], char* envp[])
{
  char buffer[8192];
  int fd;
  int count;
  int i ,isSmodeIsOn=0;
  char sModeChar;
  char d_type,lastFileNameChar;
  ent* e1;
  fd = system_call(SYS_OPEN, "." ,0 ,0);

  count = system_call(SYS_GETDENTS ,fd ,buffer,8192);
  for(i=1 ; i<argc ; i++){
    if(strcmp(argv[i],"-s")==0){
      isSmodeIsOn=1;
      i++;
      if(i>=argc){
        system_call(SYS_WRITE , STDERR , "Error .\\flame2 -s [CHAR]" , 24); 
        system_call(SYS_WRITE , STDERR , "\n" , 1);
        system_call(1,0x55);
      }
      sModeChar = argv[i][0];
    }
  }



  for(i = 0 ; i<count;){
    e1 = (ent*)(i+buffer);
    d_type = *(buffer+i+ e1->len -1);
    lastFileNameChar = *(buffer+i+ e1->len -3);
    if(isSmodeIsOn && d_type==DT_REG){
      if(lastFileNameChar==sModeChar){
        system_call(SYS_WRITE ,STDOUT ,e1->buf ,strlen(e1->buf));
        system_call(SYS_WRITE ,STDOUT ,"\n" ,1);
      }
    }
    i+=e1->len;
  }
  return 0;
}