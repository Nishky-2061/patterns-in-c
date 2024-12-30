#include<stdio.h>
int main()
{
    int i,j,n,m;
    printf("Enter the number of rows:");
    scanf("%d",&n);
    printf("Enter the number of column:");
    scanf("%d",&m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}