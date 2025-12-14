#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"details.h"
void save(books *ptr,char *s)
{
	FILE *fp=fopen(s,"w");
	books *tp=ptr;
	while(tp!=0)
	{
		fprintf(fp,"%d\t%s\t%s\t%d\n",tp->bookid,tp->book_name,tp->au_name,tp->qty);
		//ptr=ptr->next;
		tp=tp->next;
	}
	fclose(fp);
}
void file_save(books **ptr,char *s,int *flag)
{
	*flag=1;
	int x=1;
	FILE *fp=fopen(s,"r");
	if(fp==NULL)
	{
		return;
	}
	else
	{
		while(x!=-1)
		{
			books *tp=(books *)malloc(sizeof(books));
			x=fscanf(fp,"%d %[^\t] %[^\t] %d\n",&tp->bookid,tp->book_name,tp->au_name,&tp->qty);
			if(x!=-1){
				if(*ptr==NULL)
				{
					tp->next=*ptr;
					*ptr=tp;
				}
				else
				{
					books *last=*ptr;
					while(last->next!=0) last=last->next;
					tp->next=last->next;
					last->next=tp;
				}
			}
		}
	}
}
void issue_save(issue *ptr,char *s)
{
	FILE *fp=fopen(s,"w");
	issue *tp=ptr;
	while(tp!=0)
	{
		fprintf(fp,"%d\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%.2f\n",tp->userid,tp->bookid,tp->user_name,tp->issue_book,tp->issue_au,tp->qty,tp->issue_date,tp->due_date,tp->ret_date,tp->fine);

		//ptr=ptr->next;
		tp=tp->next;
	}
	fclose(fp);
}
void ret_issue_save(issue **ptr,char *s,int *flag)
{
	*flag=1;
	int x=9;
	char arr[50];
	float d;
	FILE *fp=fopen(s,"r");
	if(fp==NULL)
	{
		return;

	}
	else
	{
		while(x!=-1)
		{
			issue *tp=(issue *)malloc(sizeof(issue));
			x=fscanf(fp,"%d %d %[^\t] %[^\t] %[^\t] %d %s %s %s %f\n",&tp->userid,&tp->bookid,tp->user_name,tp->issue_book,tp->issue_au,&tp->qty,tp->issue_date,tp->due_date,tp->ret_date,&d);
			if(x!=-1){
				if(*ptr==NULL)
				{
					time_t t = time(NULL);
					struct tm *future = localtime(&t);


					sprintf(arr, "%d-%d-%d",
							future->tm_mday,
							future->tm_mon + 1,
							future->tm_year + 1900);


					int d, m, y;
					sscanf(arr, "%d-%d-%d", &d, &m, &y);

					struct tm dt_now = {0};
					dt_now.tm_mday = d;
					dt_now.tm_mon  = m - 1;
					dt_now.tm_year = y - 1900;


					int d2, m2, y2;
					sscanf(tp->issue_date, "%d-%d-%d", &d2, &m2, &y2);

					struct tm dt_issue = {0};
					dt_issue.tm_mday = d2;
					dt_issue.tm_mon  = m2 - 1;
					dt_issue.tm_year = y2 - 1900;


					int days = (int)(difftime(mktime(&dt_now), mktime(&dt_issue)) / 86400.0);

					if (days > 7) {
						days -= 7;
						tp->fine = days * 0.50;
					} 
					else 
						tp->fine = 0;

					tp->next = *ptr;
					*ptr = tp;

				}
				else
				{
					time_t t = time(NULL);
					struct tm *future = localtime(&t);

					
					sprintf(arr, "%d-%d-%d",
							future->tm_mday,
							future->tm_mon + 1,
							future->tm_year + 1900);

					
					int d, m, y;
					sscanf(arr, "%d-%d-%d", &d, &m, &y);

					struct tm dt_now = {0};
					dt_now.tm_mday = d;
					dt_now.tm_mon  = m - 1;
					dt_now.tm_year = y - 1900;

					
					int d2, m2, y2;
					sscanf(tp->issue_date, "%d-%d-%d", &d2, &m2, &y2);

					struct tm dt_issue = {0};
					dt_issue.tm_mday = d2;
					dt_issue.tm_mon  = m2 - 1;
					dt_issue.tm_year = y2 - 1900;

					
					int days = (int)(difftime(mktime(&dt_now), mktime(&dt_issue)) / 86400.0);

					if (days > 7) {
						days -= 7;
						tp->fine = days * 0.50;
					}
					else
						tp->fine = 0;

					issue *last=*ptr;
					while(last->next!=0) last=last->next;
					tp->next=last->next;
					last->next=tp;
				}
			}
		}
	}
}
void user_save(user *ptr,char *s)
{
	FILE *fp=fopen(s,"w");
	user *tp=ptr;
	while(tp!=0)
	{
		fprintf(fp,"%d\t%s\n",tp->userid,tp->user_name);
		//ptr=ptr->next;
		tp=tp->next;
	}
	fclose(fp);
}
void ret_save(user **ptr,char *s,int *flag)
{
	*flag=1;
	int x=1;
	FILE *fp=fopen(s,"r");
	if(fp==NULL)
	{
		return;
	}
	else
	{
		while(x!=-1)
		{
			user *tp=(user *)malloc(sizeof(user));
			x=fscanf(fp,"%d %[^\n]",&tp->userid,tp->user_name);
			if(x!=-1){
				if(*ptr==NULL)
				{
					tp->next=*ptr;
					*ptr=tp;
				}
				else
				{
					user *last=*ptr;
					while(last->next!=0) last=last->next;
					tp->next=last->next;
					last->next=tp;
				}
			}
		}
	}
}

