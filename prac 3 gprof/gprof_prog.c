
/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3

 */

#include<stdio.h>


int main()
{
int r,c,i,j,k;
int arr1[3][3],arr2[3][3],arr[3][3];

printf("Enter no. of rows::");
scanf("%d",&r);

printf("Enter no. of cols::");
scanf("%d",&c);



for(i=0;i<r;i++)

   {
        for(j=0;j<c;j++)

        {
        arr1[i][j]=0;
        arr2[i][j]=0;
        arr[i][j]=0;
  }
}





printf(" ENTER ARRAY 1 ELEMENENS");

for(i=0;i<r;i++)

   {
        for(j=0;j<c;j++)

                {
                printf("Enter  arr1[%d][%d]:: ",i,j);
                scanf("%d",&arr1[i][j]);
                printf("\n");
                }
  }

printf(" ENTER ARRAY 2 ELEMENENS");

for(i=0;i<r;i++)

   {
        for(j=0;j<c;j++)

                {
                printf("Enter  arr2[%d][%d]:: ",i,j);
                scanf("%d",&arr2[i][j]);
                printf("\n");
                }
  }


for(i=0;i<r;i++)

   {
        for(j=0;j<c;j++)

                {

             for(k=0;k<3;k++)
                {

                arr[i][j]=arr[i][j]+(arr1[i][k]*arr2[k][j]);

                }

                }
}

for(i=0;i<r;i++)

   {
        for(j=0;j<c;j++)

                {

                printf("arr[%d][%d]:",i,j);
                printf("%d",arr[i][j]);
                }
        }


return 0;
}
                               