#include<stdio.h>

int main(int argc,char** argv){
	printf("argc:\t%d\n",argc);
	for(int i=0;i<argc;i++)
		printf("argv%4d:\t%s\n",i,argv[i]);
	return 0;
}

