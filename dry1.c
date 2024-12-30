#include<stdio.h>
int main()
{
    int i,j,n;
    int p=1,q=0;
    printf("Enter the number:");
    scanf("%d",&n);
    for(i=1;i<=n;i++) 
    {
        for(j=1;j<=i;j++)
        {
            if((i+j)% 2==0)
            {
               printf("%d ",p);
            }
            else{
                printf("%d ",q);
            }
            
        }
        printf("\n");
    }
}