#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int c;

	if (strcmp("./tolower",argv[0]) == 0)
	{
		while((c = getchar()) != EOF)
		{
			putchar(tolower(c));
		}
	}
	else if (strcmp("./toupper",argv[0]) == 0)
	{
		while((c = getchar()) != EOF)
		{
			putchar(toupper(c));
		}
	}
	else
	{
		printf("%s Not Found \n",argv[0]);
	}
	return 0;
}
