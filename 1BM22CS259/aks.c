#include<stdio.h>
void callbyval(int x,int y);
void callbyref(int*trx,int*try);

int main()

{
    int x,y,temp;
    printf("enter the values of x and y\n");
    scanf("%d%d",&x,&y);


callbyval(x,y);
callbyref(&x,&y);
}


 void callbyval(int x,int y)
{
    int temp=x;
    x=y;
    y=temp;
    printf("the values of x and y after swapping using call by value is %d %d\n",x,y);
}
void callbyref(int*trx,int*try)
{
    int temp=* trx;
    *trx=*try;
    *try=temp;
    printf("the values of x and y after swapping using call by reference is %d %d\n",*trx,*try);
}



