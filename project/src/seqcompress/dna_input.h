#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int return_dna(char *dna,FILE *fp);


int return_dna(char *dna,FILE *fp)
{
	char temp[300];
//to jump the "\n" in each line
	while(fgets(temp,255,fp))
	{	
		fscanf(fp,"%s",temp);
		strcat(dna,temp);
	}
	
	return strlen(dna);
}
