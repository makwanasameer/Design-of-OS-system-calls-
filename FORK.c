/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/

#include<stdio.h>
#include<unistd.h>
int main()
{
        int fd[2],check=0,pid,temp1,temp2;
        char buffer[80];
        check=pipe(fd);
        pid=fork();

        printf("pid = %d\n",pid);

        if(check==-1)
        {
                printf("pipe not created :%d",check);
        }


        if(pid==0)
        {       close(fd[0]);
                printf("Parent process executing\n");
                temp1=scanf("%s",buffer);
//              printf("temp1=%d",temp1);
                temp1=write(fd[1],&buffer,80);
//              printf("temp1=%d",temp1);






        }
        if(pid!=0)
        {       close(fd[1]);



                temp2=read(fd[0],&buffer,80);
        //      printf("temp2:%d",temp2);
                printf("Child process executing\n");
                temp2=printf("child read :: %s\n",buffer);
        //      printf("temp2:%d",temp2);


        }





        return(0);

}
      