/* function-sample.c */
# include <stdio.h>
int kan(int x,int y); /*関数のプロトタイプ宣言*/

int main(void)
{
  int a,b,c;
  printf("aとbの値を入力する。入力データの区切りは空白。\n");
  scanf("%d %d",&a,&b);
  c=kan(a,b);
  printf("c=%d\n",c);
}

int kan(int x, int y)
{
  int sum;
  sum=x+y;
  x=0;
  return sum;
}
