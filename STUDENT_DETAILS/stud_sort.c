#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"details.h"
void stud_sort_n(student *ptr)
{
	student *p=ptr;
    int c=0,a[20];
    char str[50];
    while(p!=0)
    {
        c++;
        p=p->next;
    }
    student temp[c];
    p = ptr;
    for (int i=0;i<c;i++){
        temp[i]=*p;
        temp[i].next=NULL;
        p = p->next;
    }
//    memcpy(temp,ptr,c*sizeof(student));
    for (int i=0;i<c-1;i++){
        for (int j=i+1;j<c;j++){
            if (strcmp(temp[i].name,temp[j].name)>0) {
                student tmp=temp[i];
                temp[i]=temp[j];
                temp[j]=tmp;
            }
        }
    }
	for(int i=0;i<c;i++)
	{
		printf("%d\t%s\t%d\n",temp[i].rollno,temp[i].name,temp[i].percentage);
	}
}
void stud_sort_r(student *ptr)
{
    student *p=ptr;
    int c=0,a[20];
    char str[50];
    while(p!=0)
    {
        c++;
        p=p->next;
    }
    student temp[c];
    p = ptr;
    for (int i=0;i<c;i++){
        temp[i]=*p;
        temp[i].next=NULL;
        p = p->next;
    }
//    memcpy(temp,ptr,c*sizeof(student));
    for (int i=0;i<c-1;i++){
        for (int j=i+1;j<c;j++){
            if ((temp[i].percentage)<(temp[j].percentage)){
                student tmp=temp[i];
                temp[i]=temp[j];
                temp[j]=tmp;
            }
        }
    }
    for(int i=0;i<c;i++)
    {
        printf("%d\t%s\t%d\n",temp[i].rollno,temp[i].name,temp[i].percentage);
    }
}
