#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[]){
  char *var,*value;

  if(argc==1 || argc>3){
    fprintf(stderr,"usage: envir var [value]\n");
    exit(1);
  }

  var=argv[1];
  value=getenv(var);
  if(value)
    printf("Variable %s has value %s\n",var,value);
  else
    printf("Variable %s hsa no value\n",var);

  if(argc==3){
    char* str;
    value=argv[2];
    str=malloc(strlen(var)+strlen(value)+2);
    if(!str){
      fprintf(stderr,"out of memory\n");
      exit(1);
    }

    strcpy(str,var);
    strcat(str,"=");
    strcat(str,value);
    printf("Calling putenv with: %s\n",str);
    if(putenv(str)!=0){
      fprintf(stderr,"putenv failed\n");
      exit(1);
    }

    value=getenv(var);
    if(value)
      printf("New value of %s is %s\n",var,value);
    else
      printf("New value of %s is null??\n",var);
  }

  exit(0);
}

