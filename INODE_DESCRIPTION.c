/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/


#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
        struct stat obj;
        int i,j,temp,perm,octal=0;
        i=stat(argv[1],&obj);
        printf("return values of stat function=%d\n",i);


 printf("device =%d\n",obj.st_dev);      /* device */
 printf("inode =%d\n",obj.st_ino);      /* inode */
 printf("protection=%o\n",obj.st_mode);

j=obj.st_mode;
perm=j;

        while(j>0)
        {

                temp=j%8;
                octal=(octal*10)+temp;
                j=j/8;
        }

        while(j>0)
        {
        //      printf("j=%d",j);

                temp=j%8;
        //      printf("temp=%d",temp);
                if(temp==4)
                {
                        printf("r--");
                }
                else if(temp==2)
                {
                        printf("-w-");
                }
                else if(temp==1)
                {
                        printf("--e");
                }
                else if(temp==6)
                {
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
        struct stat obj;
        int i,j,temp,perm,octal=0;
        i=stat(argv[1],&obj);
        printf("return values of stat function=%d\n",i);


 printf("device =%d\n",obj.st_dev);      /* device */
 printf("inode =%d\n",obj.st_ino);      /* inode */
 printf("protection=%o\n",obj.st_mode);

j=obj.st_mode;
perm=j;

        while(j>0)
        {

                temp=j%8;
                octal=(octal*10)+temp;
                j=j/8;
        }

        while(j>0)
        {
        //      printf("j=%d",j);

                temp=j%8;
        //      printf("temp=%d",temp);
                if(temp==4)
                {
                        printf("r--");
                }
                else if(temp==2)
                {
                        printf("-w-");
                }
                else if(temp==1)
                {
                        printf("--e");
                }
                else if(temp==6)
                {
                        printf("rw-");
                }
                else if(temp==5)
                {
                        printf("r-e");
                }
                else if(temp==3)
                {
                        printf("-we");
                }
                else if(temp==7)
                {
                        printf("rwe");
                }
                printf("|");

                j=j/10;
        }


 printf("protection=%o\n",(obj.st_mode)%01000);     /* protection */




 printf("number of hard links =%d\n",obj.st_nlink);    /* number of hard links */
 printf("user id of owner=%d\n",obj.st_uid);      /* user ID of owner */
 printf("group id of qwner=%d\n",obj.st_gid);      /* group ID of owner */
 printf("device type if inode device\n",obj. st_rdev);     /* device type (if inode device) */
 printf("total size in bytes=%d\n",obj.st_size);     /* total size, in bytes */
 printf("blocksize for file system i/o=%d\n",obj.st_blksize);  /* blocksize for filesystem I/O */
 printf("no of blocks allocated=%d\n",obj.st_blocks);   /* number of blocks allocated */
 printf("time of last access =%s\n",ctime(&obj.st_atime));    /* time of last access */
 printf("time of last modification=%s\n",ctime(&obj.st_mtime));    /* time of last modification */
 printf("time of last access=%s\n",ctime(&obj.st_ctime));    /* time of last status change */
        return(0);
}
      