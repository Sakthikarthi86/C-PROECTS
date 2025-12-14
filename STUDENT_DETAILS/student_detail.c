#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"details.h"
//#include"stud_add.c"
//#include"stud_del.c"
//#include"stud_show.c"
//#include"stud_mod.c"
//#include"stud_save.c"
//#include"rev_print.c"
//#include"stud_sort.c"

//void stud_del(student**,int *);
//void stud_add(student *,student **,unsigned int);
//int stu_del(student **,int *,int);
//void stu_del1(student **,int *,char *);
int main()
{
	unsigned int i=1,res,op,roll,flag=0;
	student *hptr=0;
	char choice,del_name[50],del_rec,per,rec_file[50]="student_details";

	file_save(&hptr,rec_file,&flag);
	system("clear");
label:
	printf("*********   STUDENT RECORD MENU *********\n");
	printf("\t|A/a\t:Add new record\n");
	printf("\t|D/a\t:Delete a record\n");
	printf("\t|S/s\t:Show the list\n");
	printf("\t|M/m\t:Modify a record\n");
	printf("\t|V/v\t:Save\n");
	printf("\t|E/e\t:Exit\n");
	printf("\t|T/t\t:Sort the list\n");
	printf("\t|L/l\t:Delete all the records\n");
	printf("\t|R/r\t:Reverse the list\n");
	printf("******************************************\n");


	printf("Enter your choice:");
	scanf(" %c",&choice);

	if((choice=='a')||(choice=='A'))
	{
		system("clear");
		flag=0;
		stud_add(&hptr,i);
		system("clear");
		goto label;
	}
	else if((choice=='D')||(choice=='d'))
	{
del:
		system("clear");
		if(hptr==0){
			printf("No record was found\n");
			goto label;
		}
		printf("*******************************\n");
		printf("Enter:\n");
		printf("R/r\t:Enter Rollno to Delete\n");
		printf("N/n\t:Enter Name Delete\n");
		printf("*******************************\n");
		printf("Enter your choice:");
		scanf(" %c",&del_rec);
		if((del_rec=='R')||(del_rec=='r'))
		{
			printf("Enter the Rollno:");
			scanf("%d",&op);
			stu_del_r(&hptr,op,&flag);
			system("clear");
			goto label;
		}
		else if((del_rec=='N')||(del_rec=='n'))
		{
			student *temp=hptr;
			printf("Enter the Name:");
			scanf("%s",del_name);
			while(temp!=0)
			{
				if(strcmp(temp->name,del_name)==0){
					system("clear");
					stu_del_n(&hptr,del_name,&flag);
					goto label;
				}
			}
		}
		else
		{
			system("clear");
			printf("Enter valid input");
			printf("do you want to exit[y/n]:");
			scanf(" %c",&per);
			if(per=='n')
			goto del;
			else
				goto label;
		}
	}

	else if((choice=='S')||(choice=='s'))
	{
		if(hptr==0)
		{
			system("clear");
			printf("No data was stored\n");
			goto label;
		}
		else{
		system("clear");
		stud_show(hptr);
		printf("Please any key and Enter to Exit:");
		scanf(" %c",&per);
		printf("\n");
		if(per>=0)
		{
			system("clear");
			goto label;
		}
		}
	}
	else if((choice=='M')||(choice=='m'))
	{
		system("clear");
		if(hptr==0){
			printf("No record was found!");
			goto label;
		}
		mod:
		printf("Enter which record to search for modification\n");
		printf("|R/r\t : To Search Rollno\n");
		printf("|N/n\t : To Search Name\n");
		printf("_________________________________\n");
		printf("Enter your choice:");
		scanf(" %c",&per);

		if((per=='R')||(per=='r'))
		{
			student *ptr=hptr;
			printf("Enter the Rollno\n");
			scanf("%d",&op);
			while(ptr!=0)
			{
				if((ptr->rollno)==op){
					stud_mod_r(hptr,op);
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
				printf("student record was modified!\n");
				goto label;
			}

		}
		else if((per=='N')||(per=='n'))
		{
			student *last=hptr;
			printf("Enter the name:");
			scanf("%s",del_name);
			while(last!=0)
			{
				if(strcmp(last->name,del_name)==0)
				{
					stud_mod_n(hptr,del_name);
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
				printf("student record was modified!\n");
				goto label;
			}
		}
		else
		{
			printf("Enter valid input\n");
			goto mod;
		}


	}
	else if((choice=='V')||(choice=='v'))
	{
		system("clear");
		flag=1;
		save(hptr,rec_file);
		goto label;
	}
	else if((choice=='E')||(choice=='e'))
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
	else if((choice=='T')||(choice=='t'))
	{
		system("clear");
		if(hptr==0){
			printf("No record was found\n");
			goto label;
		}
		printf("For sorting:\n");
		printf("*****************************\n");
		printf("N/n\t:Name\nP/p\t:Percentage\n");
		printf("*****************************\n");
		printf("Enter your choice:");
		scanf(" %c",&per);
		if(per=='N'||per=='n'){
		stud_sort_n(hptr);
		goto label;
		}
		else if(per=='p'||per=='P')
		{
			stud_sort_r(hptr);
			goto label;
		}
		goto label;
	}
	else if((choice=='L')||(choice=='l'))
	{
        if(hptr==0){
			system("clear");
            printf("No record was found\n");
            goto label;
        }
		printf("please confirm to delete all data[y/n]:");
		scanf(" %c",&per);
		if(per=='y'|| per=='Y'){
		student *temp;
		flag=0;
		while(hptr!=0)
		{
			temp=hptr;
			hptr=temp->next;
			free(temp);
		}
		system("clear");
		printf("successfully deleted all lists\n");
		goto label;
		}
		goto label;
	}
	else if((choice=='R')||(choice=='r'))
	{
		system("clear");
        if(hptr==0){
            printf("No record was found\n");
            goto label;
        }
		if(hptr==0)
        {   
			flag=1;
            system("clear");
            printf("No data was stored\n");
            goto label;
        }
		printf("***********************************\n");
		printf("Rollno\tName\tpercentage\n");
		reverse_print(hptr);
		printf("***********************************\n");
		printf("Please any key and Enter to Exit:");
        scanf(" %c",&per);
        printf("\n");
        if(per>=0)
        {
            system("clear");
            goto label;
        }
	}
	else
	{
		system("clear");
		printf("Please Enter valid input\n");
		goto label;
	}
}
