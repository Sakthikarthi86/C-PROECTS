#include<stdio.h>
#include"details.h"
void book_show(books *ptr)
{
		printf("************************************************************************************\n");
		printf("____________________________________________________________________________________\n");
		printf("BookId\t\t | Book Name\t\t | author name\t | quantity\n");	
		printf("____________________________________________________________________________________\n");
	while(ptr!=0)
	{
		printf("%-20d %-20s %-20s%d\n",ptr->bookid,ptr->book_name,ptr->au_name,ptr->qty);
		printf("____________________________________________________________________________________\n");
		ptr=ptr->next;
	}
		printf("************************************************************************************\n");
}

void issue_show(issue *ptr)
{
        printf("****************************************************************************************************************************\n");
        printf("____________________________________________________________________________________________________________________________\n");
        printf("User Id\t  |BookId    |User Name\t\t|Book Name\t|author name\t|quantity\t|Issue date\t|Due date\t|Return book\t|Fine amount\n");
        printf("____________________________________________________________________________________________________________________________\n");
    while(ptr!=0)
    {
		if(strcmp(ptr->ret_date,"nil")!=0)
        printf("%-10d%-15d%-15s%-15s%-16s%-15d%-15s%-15s%-15s%.2f\n",ptr->userid,ptr->bookid,ptr->user_name,ptr->issue_book,ptr->issue_au,ptr->qty,ptr->issue_date,ptr->due_date,ptr->ret_date,ptr->fine);
		else
		{
			printf("%-10d%-15d%-15s%-15s%-16s%-15d%-15s%-15s%-15s%.2f\n",ptr->userid,ptr->bookid,ptr->user_name,ptr->issue_book,ptr->issue_au,ptr->qty,ptr->issue_date,ptr->due_date,ptr->ret_date,ptr->fine);
		}
        printf("____________________________________________________________________________________________________________________________\n");
        ptr=ptr->next;
    }
        printf("****************************************************************************************************************************\n");
}

