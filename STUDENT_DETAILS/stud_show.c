#include<stdio.h>
#include"details.h"
void stud_show(student *ptr)
{
		printf("************************************************************\n");
		printf("______________________________________________________\n");
		printf("Rollno\t\t | Name\t\t | percentage\t\t\n");	
		printf("______________________________________________________\n");
	while(ptr!=0)
	{
		printf("%-20d %-20s%d\n",ptr->rollno,ptr->name,ptr->percentage);
		printf("______________________________________________________\n");
		ptr=ptr->next;
	}
		printf("************************************************************\n");
}
