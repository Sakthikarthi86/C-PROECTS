#include<stdio.h>
#include<stdlib.h>
#include"details.h"
void save(student *ptr,char *s)
{
	FILE *fp=fopen(s,"w");
	student *tp=ptr;
	while(tp!=0)
	{
		fprintf(fp,"%d\t\t%s\t\t%d\n",tp->rollno,tp->name,tp->percentage);
			//ptr=ptr->next;
		tp=tp->next;
	}
	fclose(fp);
}
void file_save(student **ptr,char *s,int *flag)
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
			student *tp=(student *)malloc(sizeof(student));
			x=fscanf(fp,"%d%s%d\n",&tp->rollno,tp->name,&tp->percentage);
			if(x!=-1){
			if(*ptr==NULL)
			{
				tp->next=*ptr;
				*ptr=tp;
			}
			else
			{
				student *last=*ptr;
				while(last->next!=0) last=last->next;
				tp->next=last->next;
				last->next=tp;
			}
			}
		}
	}
}
