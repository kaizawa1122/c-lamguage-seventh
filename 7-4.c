#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...);

int main(void)
{
	int day, year;
	char monthname[20];

	minscanf("%d %s %d \n", &day, monthname, &year);
	printf("day = %d monthname = %s year = %d \n", day, monthname, year);

	return 0;
}

void minscanf(char *fmt, ...)
{
	va_list ap;
	char *p,*sval;
	int *ival;
	float *fval;

	va_start(ap,fmt);
	for(p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			continue;
		}

		switch(*++p)
		{
			case 'd':
				ival = va_arg(ap, int *);
				scanf("%d", ival);
				break;
			case 'f':
				fval = va_arg(ap, float *);
				scanf("%f", fval);
				break;
			case 's':
				sval = va_arg(ap, char *);
				scanf("%s", sval);
				break;
			default:
				break;
		}
	}

	va_end(ap);
}


