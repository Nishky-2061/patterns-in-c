#include<stdio.h>
int main()
{
    int i,j,m,n;
    printf("Enter the rows:");
    scanf("%d",&n);
    printf("Enter the columns:");
    scanf("%d",&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j || i+j==n+1 )
            {
                printf("* 5
                5");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}