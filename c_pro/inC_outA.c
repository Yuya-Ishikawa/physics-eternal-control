/*inC_outA.c*/

#include <stdio.h>
#include <fbippi.h>

int main(void)
{
	int dnum=1;
	unsigned char Value;
	
	PpiOpen(dnum,0);
	PpiControl(dnum,FBIPPI_8255_CONTROLLER1,0x89);

	PpiInputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_C,&Value);
	PpiOutputPort(dnum,0,FBIPPI_PORT_A,(unsigned char)Value);

	printf("InputData; 0x%x %d %c \n",Value,Value,Value);
	PpiClose(dnum); /* Close */
	
}

