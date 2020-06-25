#include <stdio.h>

//mainの変数群
#define MAXOP 100

void push(double);
double pop(void);

//push/popの変数群
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

int main(void)
{
	int flag;
	double op,number;
	char s[MAXOP];
	char notnumber, newline;

	while (scanf("%s%c",s,&newline) == 2)
	{
		if (sscanf(s,"%lf",&number) == 1)
		{
			push(number);
		}
		else if (sscanf(s,"%c",&notnumber) == 1)
		{
			switch (notnumber)
			{
				case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '-':
					op = pop();
					push(pop() - op);
					break;
				case '/':
					op = pop();
					if (op != 0.0)
					{
						push(pop() / op);
					}
					else
					{
						flag = 1;
						printf("error: zero divisor\n");
					}
					break;
				case '%':
					op = pop();
					if (op != 0.0)
					{
						int opopfrom = pop();
						int opopto = op;
						push(opopfrom % opopto);
					}
					else
					{
						flag = 1;
						printf("error: zero divisor\n");
					}
					break;
				case '!':
					return 0;
				default:
					flag = 1;
					printf("error: unknown command %s\n", s);
					break;
			}
		}
		if (newline == '\n' && flag == 0)
		{
			printf("\t%.8g\n", pop());
		}
		else if (newline == '\n' && flag == 1)
		{
			pop();
			flag = 0;
		}
	}
	return 0;
}

//pushとpopの部分の構成
void push(double f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

