#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1024

void filediff(FILE *fp1, FILE *fp2);

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	char *prog = argv[0];

	if(argc == 3)
	{
		if((fp1 = fopen(argv[1], "r")) == NULL)
		{
			fprintf(stderr,"%s: can't open %s\n",prog, argv[1]);
			exit(0);
		}
		if((fp2 = fopen(argv[2], "r")) == NULL)
		{
			fprintf(stderr,"%s: can't open %s\n",prog, argv[2]);
			exit(0);
		}
		filediff(fp1,fp2);
		fclose(fp1);
		fclose(fp2);
	}
	else
	{
		fprintf(stderr,"Error: Not filed\n");
		exit(0);
	}
	return 0;
}

void filediff(FILE *fp1, FILE *fp2)
{
	char line1[MAXSIZE], line2[MAXSIZE];
	int count = 1;

	while((fgets(line1,MAXSIZE,fp1) != NULL) && (fgets(line2,MAXSIZE,fp2)) != NULL)
	{
		if (strcmp(line1,line2) != 0)
		{
			printf("count = %d, line = %s",count,line1);
			exit(0);
		}
			count++;
	}
}
