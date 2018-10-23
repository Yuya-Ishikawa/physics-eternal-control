#include <stdio.h>
#include <fbippi.h>
#include <unistd.h>
#include <pthread.h>

int flag = 1;
char no = '1';
int change = 0;

void *kybd();
int msleep(long count);

int main(void){

	int dnum=1,n,i,c;
	int b[8]={1,3,2,6,4,12,8,9};

	PpiOpen(dnum,0);
	PpiControl(dnum,FBIPPI_8255_CONTROLLER1,0x80);

	long speed, turn, count;
	pthread_t t1;
	pthread_create(&t1,NULL,kybd,NULL);
	speed = 400;
	count=0;

	for(i=0;i<8;i++)
	{
		PpiOutputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_A,b[i]);
		usleep(10000);	
	}

	printf("This is starting point. Waiting 3 sec......\n");
	sleep(3);	

	while(flag)
	{
		if(change)
		{
			switch(no)
			{
			case 'd':
			speed*=2;
			break;

			case 'a':
			speed/=2;
			break;

			case 'c':
			turn=1;
			break;

			case 'w':
			turn=-1;
			break;
			}
		change=0;
		}
	if(speed<10) speed*=2;

	if(turn==1){
		i++;
	} else{
		i--;
	}

	if(i==8)i=0;
	if(i==-1)i=8;

	PpiOutputPort(dnum,FBIPPI_8255_CONTROLLER1,FBIPPI_PORT_A,b[i]);

	count++;
	msleep(speed);
	printf("speed=%dmsec count=%d\n",speed,count);
	}
	pthread_join(t1,NULL);

	PpiClose(dnum);
}

void *kybd(){
	char a;
	while(flag){
		scanf("%c%*c",&a);
		if(a=='q'){
			flag=0;
		} else {
			no = a;
			change = 1;
		}
	}
}

int msleep(long msec){
	return usleep(msec*1000);
}

