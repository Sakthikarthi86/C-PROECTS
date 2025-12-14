typedef struct st
{
   int rollno;
   char name[50];
   int percentage;
   struct st *next;
}student;
void stud_add(student **,unsigned int);
void stu_del_r(student **,int,int *);
void stu_del_n(student **,char *,int *);
void stud_show(student *);
void stud_mod_r(student *,int);
void stud_mod_n(student *,char *);
void save(student *,char *);
void file_save(student **,char *,int *);
void stud_sort_n(student *);
void stud_sort_r(student *);
void reverse_print(student *);
