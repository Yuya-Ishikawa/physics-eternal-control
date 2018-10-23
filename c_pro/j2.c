#include <stdio.h>
#include <time.h>

double measure(long count){
	long i;
	double t;

	struct timespec start_time, end_time;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
		for(i=0;i<count;i++)
		;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
	t = end_time.tv_sec - start_time.tv_sec +
	   (end_time.tv_nsec - start_time.tv_nsec)/1.0E9;

	return t;
        }

int main(void){
	//input
	long count;

	printf("Enter count num\n");
	scanf("%d",&count);
	printf("Time is %f\n",measure(count));
}
