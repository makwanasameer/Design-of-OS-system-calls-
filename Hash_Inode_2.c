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
//int curr_dir[30];
int i_global=0;
int del_inode;


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

void get(void)
{
        int n=10,i;
        printf("\nThe free list elements \n");

        for(i=0;i<n;i++)
        {
                ptr=malloc(sizeof(duplicate));
               // scanf("%d",&ptr->info);
                if(i==0)
                {
                        first=ptr;
                        temp=ptr;
                        ptr->info=del_inode;
                }
                else
                {
                        ptr->info=rand();
                        temp->link=ptr;
                        temp=ptr;
                }
                ptr->link=NULL;
                ptr++;
        }

        temp=first;
        while(temp->link!=NULL)
        {
                printf("%d\n",temp->info);
                temp=temp->link;
        }


}

void hashinsert(unsigned int inode)
{

        int j=(inode%2);



                ptr1=malloc(sizeof(duplicate1));
                ptr2=malloc(sizeof(duplicate2));

                if(i_global==0)
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
                        i_global++;
                }
                else
                {
                        if(j==0)
                        {
                                ptr1->info=inode;
                                ptr2->info=rand();
                        }
                        else
                        {
                                ptr1->info=rand();
                                ptr2->info=inode;
                        }


                                temp1->link=ptr1;
                                temp1=ptr1;


                                temp2->link=ptr2;
                                temp2=ptr2;


                }
                ptr1->link=NULL;
                ptr1++;

                ptr2->link=NULL;
                ptr2++;

};

void show_hash(void)
{
        int fff=0;
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

void hashdelete(void)
{

        int no_del=0;
        temp1=first1;
        ptr1=temp1;
        temp2=first2;
        ptr2=temp2;
        printf("\nEnter the inode number to delete ?    ");
        scanf("%d",&del_inode);
        while(temp1->link!=NULL)
        {

                if(temp1->info==del_inode)
                {
                        ptr1->link=temp1->link;
                        no_del++;
                }
                if(temp2->info==del_inode)
                {
                        ptr2->link=temp2->link;
                        no_del++;
                }
                ptr1=temp1;
                ptr2=temp2;
                temp1=temp1->link;
                temp2=temp2->link;
        }
        if(no_del==0)
        {
                printf("\n No such inode no in hash queue");
        }
        else
        {
                printf("\n Inode deleted=%d",del_inode);
        }
}



int main(int argc,char *argv[])
{
        void get(void);
        void hashdelete(void);
        int count_dir_entry=0;
        unsigned int p=0;
        void show_hash(void);
        void hashinsert(unsigned int);
        struct dirent *sam_dirent;
        struct stat obj;
        DIR *samdir;

        samdir=opendir(argv[1]);

        while((sam_dirent=readdir(samdir))!=0)
        {
                        p=(sam_dirent->d_ino);
        //              curr_dir[count_dir_entry]=sam_dirent->d_ino;
        //              count_dir_entry++;
            //    printf("inode= %d    filename=%s  ",sam_dirent->d_ino,sam_dirent->d_name);
                hashinsert(p);

              //  printf("\n");
        }

        show_hash();

        hashdelete();

        show_hash();

        get();


        return(0);
}
nt main(int argc,char *argv[])
{
        void get(void);
        void hashdelete(void);
        int count_dir_entry=0;
        unsigned int p=0;
        void show_hash(void);
        void hashinsert(unsigned int);
        struct dirent *sam_dirent;
        struct stat obj;
        DIR *samdir;

        samdir=opendir(argv[1]);

        while((sam_dirent=readdir(samdir))!=0)
        {
                        p=(sam_dirent->d_ino);
        //              curr_dir[count_dir_entry]=sam_dirent->d_ino;
        //              count_dir_entry++;
            //    printf("inode= %d    filename=%s  ",sam_dirent->d_ino,sam_dirent->d_name);
                hashinsert(p);

              //  printf("\n");
        }

        show_hash();

        hashdelete();

        show_hash();

        get();


        return(0);
}

