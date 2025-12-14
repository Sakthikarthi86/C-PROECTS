#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"details.h"
void user_add(user **ptr)
{
	char str[50],str1[50];
	user *p=(user*)malloc(sizeof(user));
	static int x=1;

	srand(getpid()+(x++));
	int val=rand()%9000000+1000000;
	p->userid=val;

    printf("Enter the user details(user name)\n");
	printf("user name:");
	scanf(" %[^\n]",p->user_name);
	if(*ptr==0)
	{
		p->next=*ptr;
		*ptr=p;
	}
	else
	{
		user *last=*ptr;
		while(last->next!=0)
			last=last->next;

		p->next=last->next;
		last->next=p;
	}	
		
}
