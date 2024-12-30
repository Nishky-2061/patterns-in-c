#include<stdio.h>
int main()
{
    int i,n,j,k;
    printf("Enter the line:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
        printf(" ");
        }
    for(k=1;k<=i;k++)
    {
        printf("* ");
    }
    printf("\n");
    }
}