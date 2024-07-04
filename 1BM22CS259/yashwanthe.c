#include<stdio.h>
int factorialByvalue(int n);
int main()
{
    int num;
    printf("enter number:");
    scanf("%d",&num);

    int fac=factorialByvalue(num)
    printf("factorial of %d=%d",num,fac);
    return 0;

}
int factorialByvalue(int n);
{


    int fac=1
    for(int i=1;i<=n,i++){

        fac*=i;
    }
    return fac;
}

