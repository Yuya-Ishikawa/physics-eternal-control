/* bin_count24.c program*/
/*LED  no tentou Adake*/

#include <stdio.h>
#include <unistd.h>
#include <fbippi.h>

int safe_scanf_d();
int msleep(long msec);
int safe_scanf_d();

int main(void)
{
	int dnum=1,i,j,k,st,m3=256*256*256;
	printf("switching period(msec):");
	st = safe_scanf_d();

	PpiOpen(dnum,0);
	PpiControl(dnum,0,0x80);
	for(i=0;i<m3;i++)
	{
	j = i>>8;
	k = j>>8;
	PpiOutputPort(dnum,0,FBIPPI_PORT_C,(unsigned char)i);
	PpiOutputPort(dnum,0,FBIPPI_PORT_B,(unsigned char)j);
	PpiOutputPort(dnum,0,FBIPPI_PORT_A,(unsigned char)k);
	msleep(st);	
	}
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

int msleep(long msec)
{
	return usleep(msec*1000);
}
