#include<stdio.h>
#include<string.h>
#include"details.h"
void stud_mod_r(student *ptr,int n)
{
	student *last=ptr;char ch,s[50];int per;
	while(last!=0){
	if((last->rollno)==n)
	{
		printf("Roll :\t\t Name :\t\tpercentage\n");
		printf("%d\t\t%s\t\t%d\n",last->rollno,last->name,last->percentage);
		printf("which record do you want to modify\n");
		printf("N/n :\tName\nP/p :\tpercentage\n");
		printf("Enter your choice:");
		scanf(" %c",&ch);
		if((ch=='N')||(ch=='n'))
		{
			printf("%s\n",last->name);
			printf("Enter the Name:");
			scanf("%s",s);
			
			strcpy(last->name,s);
			break;

		}
		else if((ch=='p')||(ch=='P'))
		{
			printf("Roll:%d		Name:%s		percentage:%d",last->rollno,last->name,last->percentage);
			printf("Enter the percentage:");
			scanf("%d",&per);
			last->percentage=per;
			break;
		}
	}
	else
		last=last->next;
	}
}
void stud_mod_n(student *ptr,char *s)
{
    student *last=ptr,*p;char ch,str[50];int per,count=0;
	p=ptr;
	printf("Roll\t\tName\t\tpercentage\n");
	printf("_______________________________________\n");
    while(p!=0)
 	{
      if(strcmp(p->name,s)==0){
		  count++;

      printf("%-20d%-20s%d\n",p->rollno,p->name,p->percentage);
	  printf("_______________________________________\n");

	  	per=p->rollno;
	  }
      p=p->next;
  	}
	if(count>1){
	printf("which file do you want to modify(rollno):");
	scanf("%d",&per);
	}

    while(last!=0){
    if((strcmp(last->name,s)==0)&&((last->rollno)==per))
    {
       // printf("Roll : %d\n Name : %s\npercentage : %d\n",last->rollno,last->name,last->percentage);
        printf("which record do you want to modify\n");
        printf("N/n :\tName\nP/p :\tpercentage\n");
        printf("Enter your choice:");
        scanf(" %c",&ch);
        if((ch=='N')||(ch=='n'))
        {
            printf("%s\n",last->name);
            printf("Enter the Name:");
            scanf("%s",s);
			strcpy(last->name,s);	
			break;

        }
        else if((ch=='p')||(ch=='P'))
        {
            printf("Roll:%d\nName:%s\npercentage:%d",last->rollno,last->name,last->percentage);
            printf("Enter the percentage:");
            scanf("%d",&per);
            last->percentage=per;
			break;
        }
    }
    else
        last=last->next;
    }
}
