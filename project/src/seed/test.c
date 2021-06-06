#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *a;
	a = (char *)malloc(100*sizeof(char));
	strcpy(a,"asdaugdjkagbdhjaskdasdasadasdasda");
	
	printf("%s",a);
	free(a);
	FILE *fp = NULL;

	fp = fopen("/tmp/test.txt", "w+");
	fprintf(fp, "This is testing for fprintf...\n");
	fputs("This is testing for fputs...dsadsaadas", fp);
	fputs("This is testing for fputs...dsadsaadas", fp);
	fclose(fp);
}

