
#include <stdio.h>
#include <fbippi.h>
#include <unistd.h>

int safe_scanf_d();

int main(void)
{
	int dnum=1,n,count,i,c;
	int b[4]={3,6,12,9};

	printf("Enter switching period (usec):");
	c = safe_scanf_d();
	printf("Enter step number:");
	n = safe_scanf_d();

	PpiOpen(dnum,0);
	PpiControl(dnum,FBIPPI_8255_CONTROLLER1,0x80);
	
	for(i=0;i<4;i++)
	{
		PpiOutputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_A,b[i]);
		usleep(10000);	
	}

	printf("This is starting point. Waiting 3 sec......\n");
	sleep(3);
	count=0;
	while(count<n)
	{
		for(i=0;i<4;i++)
		{
			PpiOutputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_A,b[i]);
			count++;
		if(count>=n) break;
		printf(" output=0x%02x count=%d\n",b[i],count);
		usleep(c);	
		}
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
