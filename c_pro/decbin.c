#include <stdio.h>
#include <math.h>

int main(void){
  int value,n;
  n=1;
  scanf("%d",&value);
  
  while(value >=  pow(2,n)){
    n+=1;
    continue;
  }
  //printf("%d\n",n);

  
  int x,result[n],a;
  a=value;
    for(x=1; x<=n; x++){
      result[x]=a % 2;      
      a = a/2;
      //printf("%d\n",result[x]);
      if(a==0)
	break;
      else
	continue;
    }

    for(x=n; x>=1; x--){
      printf("%d",result[x]);
    }

  printf("\n");
  
  return 0;
 
}
