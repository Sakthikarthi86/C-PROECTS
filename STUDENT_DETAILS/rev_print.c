#include<stdio.h>
//#include"details.h"
void reverse_print(student *temp)
{
	if(temp!=0){
	reverse_print(temp->next);
	printf("%d\t\t%s\t\t%d\n",temp->rollno,temp->name,temp->percentage);
	}
}
