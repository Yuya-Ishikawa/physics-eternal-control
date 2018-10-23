#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pcigpib.h>

int msleep(long msec);
int safe_scanf_d();

int main(void){

  FILE *fp;
  fp=fopen("jikken12.txt","w");

  int adrstbl[2] = {10,-1};
  char *init = "Z";
  char *cmd = "F3,PR3,R0,M0,H0";
  char *trigger = "E";
  char *R[] = {"R4","R5","R6","R7","R8","R9"};
  double r,v;
  //double I[]={1e-3,100e-6,10e-6,1e-6,100e-9,10e-9};
  double I[] ={0.001,0.0001,0.00001,0.000001,0.0000001,0.00000001};
  char recbuf[100];
  long i,delay,len=100;

  //printf("delay(msec)=");
  //delay=safe_scanf_d();

  delay=10;

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
    r = atof(recbuf);
    v = I[i]*r;
    fprintf(fp,"%e %e\n",I[i],v);
    printf("I=%e v=%e\n",I[i],v);
  }
  PciGpibExFinishBoard(0);
  fclose(fp);
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
