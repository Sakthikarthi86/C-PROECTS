#include<stdio.h>
#include<time.h>
#include"details.h"
void retur(user *tp,user *xp,issue **ptr,books *p,int us)
{
	char arr[50];
	int x;
	issue *temp=*ptr,*tem=*ptr,*pos=*ptr;
	printf("User Id\t  |BookId    |User Name\t\t|Book Name\t|author name\t|quantity\t|Issue date\t|Due date\t|Return date\t|Fine amount\n");

	while(tem!=0)
	{
		if(tem->userid==us)
		{
					printf("____________________________________________________________________________________________________________________________\n");
					if(strcmp(tem->ret_date,"nil")==0)
					printf("%-10d %-15d %-15s %-15s %-16s %-15d %-15s %-15s %-15s %.2f\n",tem->userid,tem->bookid,tem->user_name,tem->issue_book,tem->issue_au,tem->qty,tem->issue_date,tem->due_date,tem->ret_date,tem->fine);
					tem=tem->next;
		}
		else
			tem=tem->next;
	}
	printf("please enter the book id:");
	scanf("%d",&x);
	while(temp!=0)
	{
		if(temp->bookid==x)
		{
			        system("clear");
					                            time_t t = time(NULL);
                        struct tm *future = localtime(&t);
                        sprintf(arr, "%d-%d-%d",future->tm_mday,future->tm_mon + 1,future->tm_year + 1900);
                    int days = (int)(difftime(
    mktime(&(struct tm){ .tm_mday = atoi(arr), .tm_mon = atoi(arr+3)-1, .tm_year = atoi(arr+6)-1900 }),
    mktime(&(struct tm){ .tm_mday = atoi(temp->issue_date), .tm_mon = atoi(temp->issue_date+3)-1, .tm_year = atoi(temp->issue_date+6)-1900 })
) / 86400.0);
					if(days>7)
                    {
                        days=days-7;
                        temp->fine=days*0.50;
                        printf("clear the fine amount first!\n");
                        return;
                    }
                    else{
				while(p!=0)
				{
					if(p->bookid==x)
					{
						strcpy(temp->ret_date,arr);
						p->qty+=1;
						printf("Book was returned successfully!\n");
                        return;

					}
					else
						p=p->next;
				}
					}
		}
		else
				temp=temp->next;
	}
}
