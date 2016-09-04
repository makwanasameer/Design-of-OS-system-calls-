/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/

#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
        int src,dest;
        char buffer;
        int counter=0,i=0;

        src=open(argv[1],O_RDONLY);

        dest=open(argv[2],O_WRONLY | O_CREAT);

        while(read(src,&buffer,1)>0)
        {
                if(buffer=='\n')
                {
                        counter++;
                }
                if(counter==5)
                {
                        break;
                }
        }

        while(read(src,&buffer,1))
        {

               // lseek(src,-i,SEEK_END);
               // read(src,&buffer,1);
                write( dest, &buffer, 1 );
               // i++;
        }

        close(src);
        close(dest);
        return (0);

}

