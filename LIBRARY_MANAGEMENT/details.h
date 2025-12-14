#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct st
{
   int bookid;
   char book_name[50];
   char au_name[50];
   int qty;
   struct st *next;
}books;
typedef struct lib
{
	int userid;
	char user_name[50];
	struct lib *next;

}user;
typedef struct is
{
        int userid;
        char user_name[50];
		int bookid;
        char issue_book[50];
        char issue_au[50];
        char issue_date[50];
        char due_date[50];
		char ret_date[50];
        char ret[50];
        int qty;
        float fine;
        struct is *next;

}issue;

void user_add(user **);
void book_add(books **);
void book_id(books **,int,int *);
void book_name(books **,char *,int *);
void book_show(books *);
void issue_show(issue *);
void book_upt_id(books *,int);
void book_upt_name(books *,char *);
void save(books *,char *);
void file_save(books **,char *,int *);
void issue_save(issue *,char *);
void ret_issue_save(issue **,char *,int *);
void user_save(user *,char *);
void ret_save(user **,char *,int *);
void issue_book(books *,int *,user *,issue **);
void retur(user *,user *,issue **,books *,int);
