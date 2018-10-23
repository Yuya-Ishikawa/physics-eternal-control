#include <stdio.h>
#include <fbippi.h>

int main(void)
{
	int dnum=1,j,k,max=256*256*256;
	char i;
	
	PpiOpen(dnum,0);
	PpiControl(dnum,0,0x80);

	printf("input text number or Esc(end)\n");

	do{
	scanf("%c%*c",&i);
	j = i>>8;
	k = j>>8;

	printf("%3d\n ",i);
	printf("0x%x\n",i);

	if(i==27){
		break;
	};

	PpiOutputPort(dnum,0,FBIPPI_PORT_C,(unsigned char)i);
	PpiOutputPort(dnum,0,FBIPPI_PORT_B,(unsigned char)j);
	PpiOutputPort(dnum,0,FBIPPI_PORT_A,(unsigned char)k);	
	} while(i);
	PpiClose(dnum); /* Close */
	
}

