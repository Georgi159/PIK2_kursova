#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
// #define NO NULL

int xmpParser(FILE *fp)
{
	char *line=NULL;
	size_t n=0;

	char *match=NULL;
	
	char begin=0;
	


	while(!feof(fp))
	{
		getline(&line,&n, fp);
		match=strstr(line,"<?xpacket");
		if (match)
		{
			begin=!begin;
			printf("\t\t%s",line );
			continue;
		}
		if (begin)
		{
			printf("%s",line );
		}
	}
	
	free(line);
	return 0;
}

int main(/*int argc, char const *argv[]*/)
{

	FILE *fp=fopen("balloon.jp2","r");
	if (fp == NULL) 
	{
	perror("fopen");
	exit(EXIT_FAILURE);
	}


	xmpParser(fp);


	fclose(fp);
	
	return 0;
}