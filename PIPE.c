
/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3

 */

#include<stdio.h>
#include<unistd.h>
// #include"a.h"
int main()
{
       int fd1[2],fd2[2],check1,check2,pid;
       char ch,chr[80],buffer[80];
       check1=pipe(fd1);
       check2=pipe(fd2);
       if(check1==(-1) && check2==(-1))
       {
               printf("Cannot create pipe..!!\n");
       }
       else
       {
               printf("Pipe created successfully..!!\n");
       }
       pid=fork();
       while(1)
       {
               if(pid==0)
               {
                       //printf("Child process executing...\n");
                       close(fd1[1]);
                       close(fd2[0]);
                       //printf("Child process executing...\n");
                       read(fd1[0],&chr,80);
                       printf("Child process executing...\n");
                       printf("Child has read: %s\n",&chr);
                       printf("Enter the string:");
                       scanf("%s",&buffer);
                       write(fd2[1],&buffer,80);
               //      read(fd1[0],&chr,80);
               //      printf("\nChild has read: %c\n",chr);
               }
               else
               {
                       printf("Parent process executing...\n");
                       close(fd1[0]);
                       close(fd2[1]);
                      // read(fd2[0],&buffer,80);
                      // printf("Parent has read: %s\n",buffer);
                       printf("Enter the string:");
                       scanf("%s",&chr);
                       write(fd1[1],&chr,80);
                       read(fd2[0],&buffer,80);
                       printf("Parent has read: %s\n",&buffer);


               }
       }
      // printf("Read File descriptor: %d , Write file descriptor: %d\n",fd[0],fd[1]);
       return 0;
}

