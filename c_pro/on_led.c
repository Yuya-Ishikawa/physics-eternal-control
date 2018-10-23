/* on_led.c program*/
/*LED  no tentou Adake*/

#include <stdio.h>
#include <fbippi.h>

int main(void)
{
	int dnum=1,isError,nValue;
	isError = PpiOpen(dnum,0);
	if (isError)
	{
		printf("PpiOpen error; Error No=0x%x\n",isError);
		return;
	}
	/*0x80ha,portAtoCwo syuturyoku mode ni*/
	PpiControl(dnum,FBIPPI_8255_CONTROLLER1,0x80);
	nValue=0xff;
	PpiOutputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_A,(unsigned char)nValue);
	PpiClose(dnum); /* Close */
}
