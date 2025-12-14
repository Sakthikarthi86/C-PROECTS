#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"details.h"
void book_add(books **ptr)
{
	books *p=(books*)malloc(sizeof(books));
	books *temp=*ptr;
	static int x=1;
	srand(getpid()+(x++));
	int val=rand()%90000+10000;
	p->bookid=val;
    printf("Enter the book details(book name/author name/quantity\n");
	printf("book name:");
	scanf(" %[^\n]",p->book_name);
	printf("Author name:");
	scanf(" %[^\n]",p->au_name);
	printf("quantity:");
	scanf("%d",&p->qty);
	while((temp!=0))
	{
		if((!strcmp(temp->book_name,p->book_name))&&(!strcmp(temp->au_name,p->au_name)))
		{
			temp->qty+=p->qty;
			return;
		}
		else
			temp=temp->next;
	}
	if(*ptr==0)
	{
		p->next=*ptr;
		*ptr=p;
	}
	else
	{
		books *last=*ptr;
		while(last->next!=0)
			last=last->next;

		p->next=last->next;
		last->next=p;
	}	
		
}
