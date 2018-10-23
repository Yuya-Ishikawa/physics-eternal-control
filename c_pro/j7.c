/*j7.c*/

#include <stdio.h>
#include <fbippi.h>

int safe_scanf_d();
int msleep(long msec);

int main(void)
{
	int dnum=1,st;
	unsigned char Value;

	printf("switching period(msec):");
	st = safe_scanf_d();
	
	PpiOpen(dnum,0);
	PpiControl(dnum,FBIPPI_8255_CONTROLLER1,0x89);

	do{
	PpiInputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_C,&Value);
	PpiOutputPort(dnum,0,FBIPPI_PORT_A,(unsigned char)Value);
	printf("InputData; 0x%x %d %c \n",Value,Value,Value);
	msleep(st);
	}while(Value!=255);

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

int msleep(long msec){
	return usleep(msec*1000);
}
