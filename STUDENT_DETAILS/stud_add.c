#include<stdio.h>
#include<stdlib.h>
#include"details.h"
void stud_add(student **ptr,unsigned int i)
{
	student *p=(student*)malloc(sizeof(student));
    printf("Enter the student detail(Name & Percentage):\n");
	student *tp=*ptr;
	while(tp!=0)
	{
		if(((*ptr)->rollno)==2)
		{
			i=1;
			break;
		}
		if((tp->next!=0)&&((tp->next->rollno)-(tp->rollno)!=1))
		{
			i=(tp->rollno)+1;
			break;
		}
		else
		{
			i=(tp->rollno)+1;
			tp=tp->next;
		}
	}
	p->rollno=i;
	printf("Name:");
	scanf(" %[^\n]",p->name);
	//	printf("\n");
	printf("Percentage:");
	scanf("%d",&p->percentage);
	if((*ptr==0)||(p->rollno < ((*ptr)->rollno)))
	{
		p->next=*ptr;
		*ptr=p;
	}
	else
	{
		student *last=*ptr;
		while((last->next!=0)&&(p->rollno > last->next->rollno))
			last=last->next;

		p->next=last->next;
		last->next=p;
	}	
		
}
