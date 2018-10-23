/* safe-scanf-func.c program*/
/*LED  no tentou Adake*/

#include <stdio.h>

int safe_scanf_d();

int main(void)
{
	int c, flag=1;
	while(flag)
	{
	c = safe_scanf_d();
	printf("c=%d\n",c);
	if (c==0) flag=0;
	}
}

int safe_scanf_d()
{
	int c;
	while(scanf("%d",&c)!=1)
	{
	scanf("%*s");	
	}	
	scanf("%*c");
	return c;
}
