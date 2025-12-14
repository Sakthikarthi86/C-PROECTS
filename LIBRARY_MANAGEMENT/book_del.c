#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"details.h"

void book_id(books **ptr,int n,int *flag)
{
	books *temp=*ptr,*last=*ptr,*st=*ptr;char op;
	if(temp==NULL)
	printf("No Book record was found!");
	    printf("**********************************************************\n");
            printf("Book id\t\tBook name\tauthor name\tquantity\n");
    while(st!=0)
    {
        if(st->bookid==n)
        {
            printf("%-15d %-15s %-15s%d\n",st->bookid,st->book_name,st->au_name,st->qty);
            printf("___________________________________________________________\n");
        }
        st=st->next;
    }
    printf("*****************************************************************\n");
	while(temp!=0)
	{
		if((temp->bookid)==n)
		{
			printf("please confirm to delete[y/n]:");
        	scanf(" %c",&op);
            if((op=='y')||(op=='Y')){
                *flag=0;
			if(temp==*ptr){
			*ptr=last->next;
			last->next=temp->next;
			free(temp);
			system("clear");
			printf("Bookid %d records was deleted!\n",n);
			break;
			}
			else
			{
				books *los=*ptr;
				while(los->next!=temp)
					los=los->next;

				los->next=temp->next;
            	free(temp);
				system("clear");
            	printf("Bookid %d records was deleted!\n",n);
				break;
			}
			}
			else
			{
				*flag=1;
				system("clear");
				printf("Records was not deleted!\n");
				break;
			}
		}
		else if((temp->next)==0)
		{
			printf("Enter the valid bookid\n");
			break;
		}
		else
		{
			last=temp;
			temp=temp->next;
			last=last->next;
		}
	}
}
void book_name(books **ptr,char *s,int *flag)
{
	books *temp=*ptr,*last=*ptr,*los=*ptr;int count=0,per;char op;
	printf("***********************************************************\n");
			printf("Book id\t\tBook name\tauthor name\tquantity\n");
	while(last!=0)
	{
		if(strcmp(last->book_name,s)==0)
		{
            printf("%-15d %-15s %-15s%5d\n",last->bookid,last->book_name,last->au_name,last->qty);
			printf("___________________________________________________________\n");
			count++;
		}
		last=last->next;
	}
	printf("***********************************************************\n");
	if(count==1)
	{
		printf("please confirm to delete[y/n]:");
		scanf(" %c",&op);
		    if((op=='y')||(op=='Y')){
				*flag=0;
    while(temp!=0)
    {
        if(strcmp(temp->book_name,s)==0)
        {
            if(temp==*ptr){
                *ptr=los->next;
                los->next=temp->next;
                free(temp);
				system("clear");
                printf("book name: %s records was deleted!\n",s);
                return;
            }
            else
            {
                    los->next=temp->next;
                    free(temp);
					system("clear");
                    printf("book name: %s records was deleted!\n",s);
                    return;
            }
        }
        else{
            los=temp;
            temp=temp->next;
        }
    }
    }
    else
    {
		system("clear");
        printf("File Not Deleted!\n");
		*flag=1;
    }
	}
	else if(count>1)
	{
		printf("plese select the book id to delete:");
		scanf("%d",&per);
		printf("please confirm to delete[y/n]:");
        scanf(" %c",&op);
        if((op=='y')||(op=='Y')){
			*flag=0;
		while(temp!=0)
		{
			if(temp->bookid==per)
			{
				if(los==*ptr){
                *ptr=los->next;
                los->next=temp->next;
                free(temp);
				system("clear");
                printf("book name: %s records was deleted!",s);
                return;
           		 }
            	else
            	{
                    los->next=temp->next;
                    free(temp);
					system("clear");
                    printf("book name: %s records was deleted!\n",s);
                    return;
            	}
			}
			else
			{
				los=temp;
				temp=temp->next;
			}

		}
		}
		else
		{
			*flag=1;
			system("clear");
			printf("records not deleted!\n");
		}
	}
}
