/*j8.c*/

#include <stdio.h>
#include <fbippi.h>

int safe_scanf_d();
int msleep(long msec);
int check(int led,long result);

int main(void)
{
	int dnum=1,x,i,j,k,st,t,times;
	printf("switching period(msec):");
	st = safe_scanf_d();
	printf("times:");
	times = safe_scanf_d();
	
	PpiOpen(dnum,0);
	PpiControl(dnum,0,0x80);

	int count[24];
	for(x=1;x<24;x++){
		count[x]=0;
		}

	for(t=1;t<times;t++){
	
	i = random();
/*
	j = i>>8;
	k = j>>8;
	PpiOutputPort(dnum,0,FBIPPI_PORT_C,(unsigned char)i);
	PpiOutputPort(dnum,0,FBIPPI_PORT_B,(unsigned char)j);
	PpiOutputPort(dnum,0,FBIPPI_PORT_A,(unsigned char)k);
*/
	printf("InputData; 0x%x %d %c \n",i,i,i);

	for(x=1;x<24;x++){
		count[x] += check(x,(int)i);
		}

	msleep(st);
	}

	PpiClose(dnum); /* Close */

	printf("**********************************************\n");
	for(x=1;x<24;x++){
		printf("%d\n",count[x]);
		}
	
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

int check(int led,long result){
	int i, a[24], b, c;
	a[0]=1;
	for(i=1;i<24;i++){
		a[i]=a[i-1]<<1;
		}

	b = a[led]&result;
	if(b==0){
		c = 0;
	}else{
		c = 1;
	}
	return c;
}
