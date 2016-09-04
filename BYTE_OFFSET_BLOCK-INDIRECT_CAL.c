/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/

#include<malloc.h>
#include<stdlib.h>
#include<math.h>

#include <dirent.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main()
{
        int byte,filesize;
        float blockno;
        int block_int;
        int block_modulo,current_offset,temp_offset,temp=0;
        // the size of the the data block is assumed to be 1024 bytes;

        printf("Enter the byte offset: ?\n");
        scanf("%d",&byte);
        printf("Enter the file size:   ?");
        scanf("%d",&filesize);

        blockno=(byte/1024);
//      printf("blockno: %f",blockno);
        block_int=blockno;
        printf("\nThe block no is: %d",block_int);

        block_modulo=(block_int-blockno);
//      printf("modulo :%d",block_modulo);
        current_offset=(1024*block_modulo);
        temp_offset=(byte-(block_int*1024));

        printf("\nThe offset in the block is :%d",(byte-(block_int*1024)));

        if(((filesize-(1024-temp_offset))<0))
        {
                printf("\n No look ahead block required:");
        }
        else
        {
                printf("\nThe read ahead block no is: %d",block_int+1);
        }

        printf("\n****Level of Indirection*****");

        if(block_int<10)
        {
                printf("\nDirect blocks");
        }else
        if((block_int-10)<256)
        {
                temp=block_int-10;
                printf("\nFirst Indirect block  :%d",temp);
        }else
        if((block_int-10-256)<(256*256))
        {
                temp=block_int-10-256;
                printf("\nSecond Indirect block  :%d",temp);
        }else
        if((block_int-10-256-(256*256))<(256*256*256))
        {
                temp=block_int-10-256-(256*256);
                printf("\nThird indirect block :  %d",temp);
        }
        printf("\n\n");

        return(0);
}
