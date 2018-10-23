#include <stdio.h>
int main(void)
{
  printf("Hello World\n");
  
  char a=97, b='k';
  printf("a=%c %d 0x%x\n",a,a,a);
  printf("b=%c %d 0x%x\n",b,b,b);
  
  double c,d;
  printf("input:\n");
  scanf("%lf %lf",&c,&d);
  printf("%f %f\n",c+d,c-d);
  return 0;
}

