/* bin_count24.c program*/
/*LED  no tentou Adake*/

#include <stdio.h>
#include <unistd.h>
#include <fbippi.h>

int safe_scanf_d();
int msleep(long msec);

int main(void)
{
	int dnum=1,x,i,j,k,st;
	printf("switching period(msec):");
	st = safe_scanf_d();
	
	while(1)
	{
	PpiOpen(dnum,0);
	PpiControl(dnum,0,0x80);

	i=1;
	for(x=0;x<24;x++)
	{
	i = 2*i;
	j = i>>8;
	k = j>>8;
	PpiOutputPort(dnum,0,FBIPPI_PORT_C,(unsigned char)i);
	PpiOutputPort(dnum,0,FBIPPI_PORT_B,(unsigned char)j);
	PpiOutputPort(dnum,0,FBIPPI_PORT_A,(unsigned char)k);
	msleep(st);	
	}
	PpiClose(dnum); /* Close */
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

int msleep(long msec)
{
	return usleep(msec*1000);
}
