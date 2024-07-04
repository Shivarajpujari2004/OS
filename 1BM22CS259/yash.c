#include<stdio.h>
void factorialByReference(int n,int *ans)
int main()
{


    int num,fac;
    printf("enter number");
    scanf("%d",&num);
    factorByReference(num,&fac);
    printf("factorial of %d=%d",num,fac);
    return 0;
}
void factorialByReference(int n,int*ans)
{
    *ans=1;
    for(int i=1;i<=n;i++)
        *ans *=i;
    return 0;
}
