#include<stdio.h>
#include<string.h>
#include"details.h"
void book_upt_id(books *ptr,int n)
{
	books *last=ptr;char ch,s[50];int per;
	while(last!=0){
	if((last->bookid)==n)
	{
		printf("BookId\t\t | Book Name\t\t | author name\t | quantity\n");
		printf("%-20d %-20s %-20s%d\n",last->bookid,last->book_name,last->au_name,last->qty);
		printf("which record do you want to modify\n");
		printf("A :\tbook name\nB :\tauthor name\n");
		printf("Enter your choice:");
		scanf(" %c",&ch);
		if((ch=='A')||(ch=='a'))
		{
			printf("%s\n",last->book_name);
			printf("Enter the book name:");
			scanf(" %[^\n]",s);
			
			strcpy(last->book_name,s);
			break;

		}
		else if((ch=='B')||(ch=='b'))
		{
			printf("%s\n",last->au_name);
            printf("Enter the author name:");
            scanf(" %[^\n]",s);

            strcpy(last->au_name,s);
            break;
		}
	}
	else
		last=last->next;
	}
}
void book_upt_name(books *ptr,char *s)
{
    books *p=ptr;char ch;
	while(p!=0){
	if(strcmp(p->book_name,s)==0){
		printf("BookId\t\t | Book Name\t\t | author name\t | quantity\n");
		printf("%-20d %-20s %-20s%d\n",p->bookid,p->book_name,p->au_name,p->qty);
		printf("which record do you want to modify\n");
		printf("A :\tbook name\nB :\tauthor name\n");
		printf("Enter your choice:");
		scanf(" %c",&ch);
		break;
	}
	else
	{
		p=p->next;
	}
	}
        if((ch=='A')||(ch=='a'))
        {
            printf("%s\n",p->book_name);
            printf("Enter the book name:");
            scanf("%[^\n]",s);
			strcpy(p->book_name,s);	

        }
        else if((ch=='B')||(ch=='b'))
        {
            printf("%s\n",p->au_name);
            printf("Enter the author name:");
            scanf("%[^\n]",s);
			strcpy(p->au_name,s);	
        }
}
