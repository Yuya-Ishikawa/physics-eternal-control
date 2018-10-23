/* on_led.c program*/
/*LED  no tentou Adake*/

#include <stdio.h>
#include <fbippi.h>

int safe_scanf_d();
int msleep(long msec);

int main(void)
{
	int dnum=1,isError,nValue,st,count,i;

	printf("switching period(msec):");
	st = safe_scanf_d();
	printf("switching count:");
	count = safe_scanf_d();
	
	isError = PpiOpen(dnum,0);
	if (isError)
	{
		printf("PpiOpen error; Error No=0x%x\n",isError);
		return;
	}
	/*0x80ha,portAtoCwo syuturyoku mode ni*/
	PpiControl(dnum,FBIPPI_8255_CONTROLLER1,0x80);
	
	for(i=0;i<count;i++){
	nValue=0xff;
	PpiOutputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_A,(unsigned char)nValue);
	PpiOutputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_B,(unsigned char)nValue);
	PpiOutputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_C,(unsigned char)nValue);
	msleep(st);

	nValue=0x0;
	PpiOutputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_A,(unsigned char)nValue);
	PpiOutputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_B,(unsigned char)nValue);
	PpiOutputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_C,(unsigned char)nValue);
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

int msleep(long msec){
	return usleep(msec*1000);
}
