#include<stdio.h>
int main()
{
    int i,j,n;
    int a=1;
    printf("Enter the number:");
    scanf("%d",&n);
    for(i=1;i<=n;i++) 
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",a);
            a=a+2;
        }
        printf("\n");
    }
}