
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
	long speed, count;
	pthread_t t1;
	pthread_create(&t1,NULL,kybd,NULL);
	speed = 400;
	count=0;

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
			}
		change=0;
		}
	if(speed<10) speed*=2;
	count++;
	msleep(speed);
	printf("speed=%dmsec count=%d\n",speed,count);
	}
	pthread_join(t1,NULL);
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




