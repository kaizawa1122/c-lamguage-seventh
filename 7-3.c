#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

int main(void)
{
	unsigned int a = 10;	
	char b = 'a';
	char *s = "Hello";

	minprintf("b = %c,s = %p,a = %x\n",b,s,a);

	return 0;
}

void minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	unsigned int uval; 
	double dval;
	void *pval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}

		switch(*++p)
		{
			case 'd':
				ival = va_arg(ap, int);
				printf("%d",ival);
					break;
			case 'f':
				dval = va_arg(ap,double);
				printf("%f",dval);
				break;
			case 's':
				for (sval = va_arg(ap,char *); *sval; sval++)
				{
					putchar(*sval);
				}
				break;
			case 'c':
				ival = va_arg(ap,int);
				printf("%c",ival);
				break;
			case 'p':
				pval = va_arg(ap,void *);
				printf("%p",pval);
				break;
			case 'x':
				uval = va_arg(ap,unsigned int);
				printf("%x",uval);
				break;
			default:
				putchar(*p);
				break;
		}
	}

	va_end(ap);
}
		
