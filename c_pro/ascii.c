/*ascii.c*/

#include <stdio.h>

int main(void){
	int i,j,a;
	printf("+------------------ ASCII Table ------------------+\n");
	for(i=2;i<=7;i++){
		printf("+-------------------------------------------------+\n");
		for(j=0;j<16;j++){
			a=i*16+j;
			printf("%3d ",a);		
		}	
		printf("\n");
		printf("0x%x",i);
		for(j=0;j<16;j++){
			a=i*16+j;
			printf("%c ",a);	
		}
		printf("\n");		
	}
	printf("+-------------------------------------------------+\n");
}
