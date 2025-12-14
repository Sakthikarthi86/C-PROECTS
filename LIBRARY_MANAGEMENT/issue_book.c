#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"details.h"
void issue_book(books *ptr,int *f,user *p,issue **tp)
{
	int x;
	char op,name[50],tr[50];
	books *temp=ptr;
		printf("Enter the book id:");
		scanf("%d",&x);
		while(temp!=0)
		{
			if(temp->bookid==x)
			{
				if(temp->qty<=0)
				{
					system("clear");
					printf("book is not available at this time\n");
					break;
				}
				else
				{
					system("clear");
					printf("BookId\t\t | Book Name\t\t | author name\t | quantity\n");
					printf("%-20d %-20s %-20s%d\n",temp->bookid,temp->book_name,temp->au_name,temp->qty);

						issue *sp=(issue *)malloc(sizeof(issue));
						sp->userid=p->userid;
						sp->bookid=temp->bookid;
						strcpy(sp->ret_date,"nil");
						strcpy(sp->user_name,p->user_name);
						*f=1;
						temp->qty=(temp->qty)-1;
						if(sp->qty>0)
						sp->qty+=1;
						else
							sp->qty=1;
						strcpy(sp->issue_book,temp->book_name);
						strcpy(sp->issue_au,temp->au_name);
						time_t t = time(NULL);
						struct tm *future = localtime(&t);
						sprintf(sp->issue_date, "%d-%d-%d",future->tm_mday,future->tm_mon + 1,future->tm_year + 1900);
						sp->fine=0;
						time_t xp = time(NULL)+ 7*24*3600;
						struct tm *futur = localtime(&xp);
						sprintf(sp->due_date, "%d-%d-%d",futur->tm_mday,futur->tm_mon + 1,futur->tm_year + 1900);
						if(*tp==0)
						{
							sp->next=*tp;
							*tp=sp;
						}
						else
						{
							issue *last=*tp;
							while(last->next!=0)
								last=last->next;

							sp->next=last->next;
							last->next=sp;
						}

						break;
					}
				}
			else
				temp=temp->next;
		}
		if(temp==0){
			system("clear");
			printf("the id you search was not available\n");
		}
	}
