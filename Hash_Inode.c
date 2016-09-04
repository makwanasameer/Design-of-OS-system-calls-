/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
int globalcount=0;
struct node
{
        int info;
        struct node * link;
}*ptr,*first,*temp;

struct hash1
{
        int info;
        struct hash1 *link;
}*ptr1,*first1,*temp1;

struct hash2
{
        int info;
        struct hash2 *link;
}*ptr2,*first2,*temp2;

typedef struct hash2 duplicate2;
typedef struct hash1 duplicate1;
typedef struct node duplicate;

void hashinsert(int inode)
{
        int i=0;
        int j=(inode%2);


        for(i=0;i<10;i++)
        {
                ptr1=malloc(sizeof(duplicate));
                ptr2=malloc(sizeof(duplicate));

                if(i==0)
                {
                        if(j==0)
                        {
                                ptr1->info=inode;
                                ptr2->info=rand();
                        }
                        else
                        {
                                ptr2->info=inode;
                                ptr1->info=rand();
                        }
                        first1=ptr1;
                        temp1=first1;

                        first2=ptr2;
                        temp2=first2;

                }
                else
                {
                        ptr1->info=rand();
                        temp1->link=ptr1;
                        temp1=ptr1;

                        ptr2->info=rand();
                        temp2->link=ptr2;
                        temp2=ptr2;


                }
                ptr1->link=NULL;
                ptr1++;

                ptr2->link=NULL;
                ptr2++;
        }

        temp1=first1;
        temp2=first2;
        printf("\n\nHash QUEUE1           HASH QUEUE2 :(content)\n");
        while(temp1->link!=NULL)
        {
                printf("%d                %d  \n",temp1->info,temp2->info);
                temp1=temp1->link;
                temp2=temp2->link;
        }

}

void get(void)
{
        int n,i;
        printf("Enter the free list elements count? \n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                ptr=malloc(sizeof(duplicate));
                scanf("%d",&ptr->info);
                if(i==0)
                {
                        first=ptr;
                        temp=ptr;
                }
                else
                {
                        temp->link=ptr;
                        temp=ptr;
                }
                ptr->link=NULL;
                ptr++;
        }
}
void display(int inode)
{
        void insert(int);
        temp=first;
        int t=inode;
        int j=0,clear=0;
        printf("\n");
        while(temp->link!=NULL)
        {
                if(temp->info==inode)
                {
                        j++;

                }

                if(j>0&&(clear==0))
                {
                        clear=1;
                        printf("inode is in the free list ==> %d \n",inode);
                        break;
                }


                printf("number in info is %d\n",temp->info);
                temp=temp->link;
        }
        if(j==0)
        {
                printf(" \ninode no. not in the list\n");
        }
        printf("number in info is %d",temp->info);

        globalcount++;
        printf("\n");
        if(globalcount==1)
        {
                insert(t);
        }


};

void insert(int inode)
{
        void hashinsert(int);
        temp=first;
        ptr=temp;
        while(temp->link!=NULL)
        {
                if(temp->info==inode)
                {
                       ptr->link=temp->link;
                }
                ptr=temp;
                temp=temp->link;

        }
        printf("\n THE inode DELETED FROM THE FREE LIST AND ALLOCATED TO THE HASH QUEUE \n");
        display(inode);
        hashinsert(inode);
}






int main(int argc,char *argv[])
{
        int inode;
        struct stat obj;
        stat(argv[1],&obj);
        inode=obj.st_ino;
        printf("i-node==%d\n ",inode);


        void get(void);
        void display(int inode);
        void insert(int inode);
//      void reverse(void);
//      clrscr();
        get();
        printf("\n");
        display(inode);
//      reverse();
//      display(inode);
        return(0);
}
