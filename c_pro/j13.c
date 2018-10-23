#include <stdio.h>
#include <string.t>
#include <unistd.h>
#include <pcigpib.h>

double vtof(char *in, char *unit);
double htof(char *in, char *unit);

int main(void){

  FILE *fp;
  fp=fopen("wave.txt","w");

  int adrstbl[2] = {3,-1};
  char *cmd = "WREADI";
  char recbuf[9000];
  long len=9000;

  int ret;
  ret = PciGpibExInitBoard(0,0);
  if(ret){
    printf("ERROR:%d\n",ret);
    return;
  }

  PciGpibExSetIfc(0,1);
  PciGpibExSetRen(0);

  PciGpibExSendData(0,adrstbl,strlen(cmd),cmd,0);
  usleep(10000);
  PciGpibExRecvData(0,adrstbl,&len,recbuf,0);

  recbuf[len]='\0';

  char *ch,*vert,*horz,*data_str;
  char v_unit[3];
  char h_unit[3];
  long count=0;
  double v_range,h_range,data,x,y;

  ch=strtok(recbuf,",");
  vert=strtok(NULL,",");
  horz=strtok(NULL,",");

  v_range=vtof(vert,v_unit);
  h_range=htof(horz,h_unit);

  fprintf(fp,"#xlabel %s,ylabel %s \n",h_unit,v_unit);

  while(data_str=strtok(NULL,",")){
    data=atof(data_str);
    x=h_range*count/200;
    y=(data-128)*v_range/25;
    fprintf(fp,"%f %f\n",x,y);
    count++;
  }

  PciGpibExFinishBoard(0);
  fclose(fp);
}

double vtof(char *in,char *unit){
  double num;
  char data[4];
  data[0]= *(in+1);
  data[1]= *(in+2);
  data[2]= *(in+3);
  data[3]='\0';

  num=atof(data);

  *unit=*(in+4);
  *(unit+1)=*(in+5);
  *(unit+2)='\0';

  return num;
}

double htof(char *in, char *unit){
  double num;
  char data[4];
  data[0]=*in;
  data[1]=*(in+1);
  data[2]=*(in+2);
  data[3]='\0';

  num=atof(data);
  *unit=*(in+3);
  *(unit+1)=*(in+4);
  *(unit+2)='\0';

  return num;
}
