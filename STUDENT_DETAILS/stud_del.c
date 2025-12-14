#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"details.h"

void stu_del_r(student **ptr,int n,int *flag)
{
	student *temp=*ptr,*last=*ptr,*st=*ptr;char str[50],op;
	if(temp==NULL)
	printf("No student record found!");
	    printf("*********************************************\n");
            printf("Rollno:\t\tName\t\tPercentage\n");
    while(st!=0)
    {
        if(st->rollno==n)
        {
            printf("%-15d %-15s%d\n",st->rollno,st->name,st->percentage);
            printf("_______________________________________\n");
        }
        st=st->next;
    }
    printf("*********************************************\n");
	while(temp!=0)
	{
		if((temp->rollno)==n)
		{
			printf("please confirm to delete[y/n]:");
        	scanf(" %c",&op);
            if((op=='y')||(op=='Y')){
                *flag=0;
			if(last==*ptr){
			*ptr=last->next;
			last->next=temp->next;
			free(temp);
			system("clear");
			printf("rollno %d records was deleted!\n",n);
			break;
			}
			else
			{
				student *los=*ptr;
				while(los->next!=temp)
					los=los->next;

				los->next=temp->next;
            	free(temp);
				system("clear");
            	printf("rollno %d records was deleted!\n",n);
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
			printf("Enter the valid rollno\n");
		//	goto del;
		}
		else
		{
			last=temp;
			temp=temp->next;
			last=last->next;
		}
	}
}
void stu_del_n(student **ptr,char *s,int *flag)
{
	student *temp=*ptr,*last=*ptr,*los=*ptr;int count=0,per;char op;
	printf("*********************************************\n");
			printf("Rollno:\t\tName\t\tPercentage\n");
	while(last!=0)
	{
		if(strcmp(last->name,s)==0)
		{
			printf("%-15d %-15s%d\n",last->rollno,last->name,last->percentage);
			printf("_______________________________________\n");
			count++;
		}
		last=last->next;
	}
	printf("*********************************************\n");
	if(count==1)
	{
		printf("please confirm to delete[y/n]:");
		scanf(" %c",&op);
		    if((op=='y')||(op=='Y')){
				*flag=0;
    while(temp!=0)
    {
        if(strcmp(temp->name,s)==0)
        {
            if(los==*ptr){
                *ptr=los->next;
                los->next=temp->next;
                free(temp);
				system("clear");
                printf("name: %s records was deleted!\n",s);
                return;
            }
            else
            {
                    los->next=temp->next;
                    free(temp);
					system("clear");
                    printf("Name: %s records was deleted!\n",s);
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
		printf("plese select the rollno to delete:");
		scanf("%d",&per);
		printf("please confirm to delete[y/n]:");
        scanf(" %c",&op);
        if((op=='y')||(op=='Y')){
			*flag=0;
		while(temp!=0)
		{
			if(temp->rollno==per)
			{
				if(los==*ptr){
                *ptr=los->next;
                los->next=temp->next;
                free(temp);
				system("clear");
                printf("name: %s records was deleted!",s);
                return;
           		 }
            	else
            	{
                    los->next=temp->next;
                    free(temp);
					system("clear");
                    printf("Name: %s records was deleted!\n",s);
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





