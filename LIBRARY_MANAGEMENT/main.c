#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"details.h"
//#include"user_add.c"
//#include"book_add.c"
//#include"book_del.c"
//#include"book_view.c"
//#include"upt_book.c"
//#include"book_save.c"
//#include"issue_book.c"
//#include"return_book.c"
int main()
{
	unsigned int res,op,roll,flag=0,choice,id;
	books *hptr=0;
	user *hpt=0;
	issue *pt=0;
	char del_name[50],us_name[50],del_rec,per,rec_file[50]="book_details.csv",rec_user[50]="user_details.csv",rec_issue[50]="issue_details.csv";

	file_save(&hptr,rec_file,&flag);
	ret_save(&hpt,rec_user,&flag);
	ret_issue_save(&pt,rec_issue,&flag);
	system("clear");
label:
	printf("*********   BOOK MANAGEMENT MENU *********\n");
	printf("\t|0\t:Add new user\n");
	printf("\t|1\t:Add new books\n");
	printf("\t|2\t:Remove book\n");
	printf("\t|3\t:View all books\n");
	printf("\t|4\t:Update book details\n");
	printf("\t|5\t:Search books\n");
	printf("\t|6\t:Issue book\n");
	printf("\t|7\t:return book\n");
	printf("\t|8\t:List issued book\n");
	printf("\t|9\t:Save\n");
	printf("\t|10\t:Exit\n");
	printf("******************************************\n");


	printf("Enter your choice:");
	scanf(" %d",&choice);

	if(choice==0)
	{
		system("clear");
		flag=0;
		user_add(&hpt);
		system("clear");
		goto label;
	}
	else if(choice==1)
	{
		system("clear");
		flag=0;
		book_add(&hptr);
		system("clear");
		goto label;
	}

	else if(choice==2)
	{
del:
		system("clear");
		if(hptr==0){
			printf("No record was found\n");
			goto label;
		}
		printf("*******************************\n");
		printf("Enter:\n");
		printf("A\t:Enter BookId\n");
		printf("B\t:Enter Book Name\n");
		printf("D\t:Back to main menu\n");
		printf("*******************************\n");
		printf("Enter your choice:");
		scanf(" %c",&del_rec);
		if((del_rec=='A')||(del_rec=='a'))
		{
			printf("Enter the BookId:");
			scanf("%d",&op);
			book_id(&hptr,op,&flag);
			system("clear");
			goto label;
		}
		else if((del_rec=='B')||(del_rec=='b'))
		{
			books *temp=hptr;
			printf("Enter the Name:");
			scanf(" %[^\n]",del_name);
			while(temp!=0)
			{
				if(strcmp(temp->book_name,del_name)==0){
					system("clear");
					book_name(&hptr,del_name,&flag);
					goto label;
				}
			}
		}
		else if((del_rec=='D')||(del_rec=='d'))
		{
			system("clear");
			goto label;
		}
		else
		{
			system("clear");
			printf("Enter valid input\n");
			printf("do you want to exit[y/n]:");
			scanf(" %c",&per);
			if(per=='n')
				goto del;
			else
				goto label;
		}
	}
	else if(choice==3)
	{
		if(hptr==0)
		{
			system("clear");
			printf("No data was stored\n");
			goto label;
		}
		else{
			system("clear");
			book_show(hptr);
			printf("Press any key and Enter to Exit:");
			scanf(" %c",&per);
			printf("\n");
			if(per>=0)
			{
				system("clear");
				goto label;
			}
		}
	}
	else if(choice==4)
	{
		system("clear");
		if(hptr==0){
			printf("No record was found!");
			goto label;
		}
mod:
		printf("Enter which record to search for modification\n");
		printf("|A\t : By book id\n");
		printf("|B\t : By book Name\n");
		printf("|D\t : Back to main menu\n");

		printf("_________________________________\n");
		printf("Enter your choice:");
		scanf(" %c",&per);

		if((per=='A')||(per=='a'))
		{
			books *ptr=hptr;
			printf("Enter the book id\n");
			scanf("%d",&op);
			while(ptr!=0)
			{
				if((ptr->bookid)==op){
					book_upt_id(hptr,op);
					flag=0;
					break;
				}
				else
					ptr=ptr->next;
			}
			if(ptr==NULL){
				system("clear");
				printf("Enetr the valid number:\n");
				goto mod;
			}
			else
			{
				system("clear");
				printf("book record was modified!\n");
				goto label;
			}

		}
		else if((per=='B')||(per=='b'))
		{
			books *last=hptr;
			printf("Enter the book name:");
			scanf("%[^\n]",del_name);
			while(last!=0)
			{
				if(strcmp(last->book_name,del_name)==0)
				{
					book_upt_name(hptr,del_name);
					flag=0;
					break;
				}
				last=last->next;
			}
			if(last==NULL){
				system("clear");
				printf("\n\nEnter valid name:\n");
				goto mod;
			}
			else
			{
				system("clear");
				printf("book record was modified!\n");
				goto label;
			}
		}
		else if((per=='D')||(per=='d'))
		{
			system("clear");
			goto label;
		}
		else
		{
			printf("Enter valid input\n");
			goto mod;
		}


	}
	else if(choice==9)
	{
		system("clear");
		flag=1;
		save(hptr,rec_file);
		user_save(hpt,rec_user);
		issue_save(pt,rec_issue);
		goto label;
	}
	else if(choice==10)
	{
		system("clear");
		if(flag==1)
			return 0;
		else
		{
			printf("**********************************\n");

			printf("\tEnter:\n");
re:
			printf("\tS/s\t:Save and Exit\n");
			printf("\tE/e\t:Exit Without Saving\n");
			printf("**********************************\n");
			printf("Enter your choice:");
			scanf(" %c",&per);
			if((per=='E')||(per=='e'))
				return 0;
			else if((per=='S')||(per=='s'))
			{
				save(hptr,rec_file);
				user_save(hpt,rec_user);
				issue_save(pt,rec_issue);
				flag=1;
				system("clear");
				printf("File saved successfully\n");
				return 0;
			}
			else{
				printf("Reenter the input:");
				goto re;
			}
		}
	}
	else if(choice==5)
	{
		system("clear");
		if(hptr==0){
			printf("No record was found\n");
			goto label;
		}
		printf("\t\tsearch books\n");
		printf("\t\tA :\tby book id\n\t\tB :\tby book name\n\t\tC :\tby author name\n\t\tD :\tBack to main menu\n");
		printf("Enter your choice:");
		scanf(" %c",&per);
		system("clear");
		books *temp=hptr;
		if((per=='A')||(per=='a'))
		{
			printf("please enter the book id:");
			scanf("%d",&res);
			while(temp!=0)
			{
				if(temp->bookid==res)
				{
					printf("BookId\t\t | Book Name\t\t | author name\t | quantity\n");
					printf("%-20d %-20s %-20s%d\n",temp->bookid,temp->book_name,temp->au_name,temp->qty);
					printf("Press any key and Enter to Exit:");
					scanf(" %c",&per);
					printf("\n");
					if(per>=0)
					{
						system("clear");
						goto label;
					}
				}
				else
					temp=temp->next;
			}
			if(temp==0)
			{
				system("clear");
				printf("please enter the correct details\n");
				goto label;
			}
		}
		else if((per=='B')||(per=='b'))
		{
			printf("please enter the book name:");
			scanf(" %[^\n]",del_name);
			while(temp!=0) 
			{
				if(strcmp(temp->book_name,del_name)==0)
				{
					printf("BookId\t\t | Book Name\t\t | author name\t | quantity\n");
					printf("%-20d %-20s %-20s%d\n",temp->bookid,temp->book_name,temp->au_name,temp->qty);
					printf("Press any key and Enter to Exit:");
					scanf(" %c",&per);
					printf("\n");
					if(per>=0)
					{
						system("clear");
						goto label;
					}
				}
				else
					temp=temp->next;
			}
			if(temp==0)
			{
				system("clear");
				printf("please enter the correct details\n");
				goto label;
			}
		}
		else if((per=='C')||(per=='c'))
		{
			printf("please enter the author name:");
			scanf(" %[^\n]",del_name);
			while(temp!=0)
			{
				if(strcmp(temp->au_name,del_name)==0)
				{
					printf("BookId\t\t | Book Name\t\t | author name\t | quantity\n");
					printf("%-20d %-20s %-20s%d\n",temp->bookid,temp->book_name,temp->au_name,temp->qty);
					printf("Press any key and Enter to Exit:");
					scanf(" %c",&per);
					printf("\n");
					if(per>=0)
					{
						system("clear");
						goto label;
					}
				}
				else
					temp=temp->next;
			}
			if(temp==0)
			{
				system("clear");
				printf("please enter the correct details\n");
				goto label;
			}
		}
		else if((per=='D')||(per=='d'))
		{
			system("clear");
			goto label;
		}
		else
		{
			system("clear");
			printf("enter the valid input\n");
			goto label;
		}
	}
	else if(choice==6)
	{
		here:
		system("clear");
		user *temp=hpt;int f=0;
		issue *det=pt;
		printf("please enter the userid:");
		scanf("%d",&f);
		while(temp!=0)
		{
			if(temp->userid==f){
				issue_book(hptr,&f,temp,&pt);
				//issue_add(&pt);
				flag=0;
				system("clear");
				if(f==1)
				printf("book issued successfully\n");
				break;
			}
			else
				temp=temp->next;
		}
		if(temp==0)
			goto here;
			goto label;
	}
	else if(choice==8)
	{
            system("clear");
            issue_show(pt);
            printf("Press any key and Enter to Exit:");
            scanf(" %c",&per);
            printf("\n");
            if(per>=0)
            {
                system("clear");
                goto label;
            }
	}
	else if(choice==7)
	{
		system("clear");
		    user *xp=hpt;
			int str,str1;
    printf("please enter the userid:");
    scanf("%d",&str);
    while(xp!=0)
    {
		flag=0;
        if(xp->userid==str)
		{
			retur(hpt,xp,&pt,hptr,str);
			break;
		}
        else
			xp=xp->next;
    }
	if(xp==0)
	{
		            system("clear");
            printf("no user in this id\n");
	}
		goto label;
	}
	else
	{
		system("clear");
		printf("choose option corectly");
		goto label;
	}
}
