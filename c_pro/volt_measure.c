/*volt_measure.c R4661 で電圧を測定する*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pcigpib.h>

int msleep(long msec);
int safe_scanf_d();

int main(void){
  int adrstbl[2] = {10,-1};
  char *init = "Z";
  char *cmd = "F1,PR3,R0,M0,H0";
  char *trigger = "E";
  char *R[] = {"R2","R3","R4","R5","R6","R7"};
  char recbuf[100];
  long i,delay,len=100;

  printf("delay(msec)=");
  delay=safe_scanf_d();

  PciGpibExInitBoard(0,0);
  PciGpibExSetIfc(0,1);
  PciGpibExSetRen(0);
  PciGpibExSendData(0,adrstbl,strlen(init),init,0);
  PciGpibExSendData(0,adrstbl,strlen(cmd),cmd,0);

  for(i=0;i<6;i++){
    PciGpibExSendData(0,adrstbl,strlen(R[i]),R[i],0);
    PciGpibExSendData(0,adrstbl,strlen(trigger),trigger,0);
    msleep(delay);
    PciGpibExRecvData(0,adrstbl,&len,recbuf,0);
    recbuf[len]='\0';
    printf("%s\n",recbuf);
  }
  PciGpibExFinishBoard(0);
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
