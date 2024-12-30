#include<stdio.h>
int main()
{
    int i,j,n,m;
    printf("Enter the number of rows:");
    scanf("%d",&n);
    printf("Enter the number of columns:");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",i+1);
        }
        printf("\n");
    }
}