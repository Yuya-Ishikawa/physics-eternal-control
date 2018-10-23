#include <stdio.h>
#include <fbippi.h>

int safe_scanf_d();

int main(void)
{
	int dnum=1,i,j,k,max=256*256*256;
	
	PpiOpen(dnum,0);
	PpiControl(dnum,0,0x80);

	printf("input 10type number or 0(end)\n");

	do{
	i = safe_scanf_d();
	j = i>>8;
	k = j>>8;
	PpiOutputPort(dnum,0,FBIPPI_PORT_C,(unsigned char)i);
	PpiOutputPort(dnum,0,FBIPPI_PORT_B,(unsigned char)j);
	PpiOutputPort(dnum,0,FBIPPI_PORT_A,(unsigned char)k);	
	} while(i);
	PpiClose(dnum); /* Close */
	
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
