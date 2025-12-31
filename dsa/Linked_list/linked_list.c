#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
char usn[11];
char name[25];
int sem;
char branch[5];
unsigned long long phno;
};
typedef struct student STUD;
struct node
{
 char usn[11];
 char name[25];
 int sem;
 char branch[5];
 unsigned long long phno;
 struct node *next;
};
typedef struct node NODE;
NODE *first;
NODE *copynode(STUD s)
{
 NODE *temp;
 temp=(NODE *)malloc(sizeof(NODE));
 if(temp==NULL)
 	printf("Memory not allocated\n");
 else
 {
 strcpy(temp->usn,s.usn);
 strcpy(temp->name,s.name);
 strcpy(temp->branch,s.branch);
 temp->sem=s.sem;
 temp->phno=s.phno;
 temp->next=NULL;
 return temp;
 }
}
void addrear(STUD s)
{
 NODE *temp, *cur;
 temp = copynode(s);
 if(first==NULL)
 	{
 	temp=first;
 	return;
 	}
 while(cur->next!=NULL)
 	cur=cur->next;
 cur->next=temp;
 return;
}
void addfront(STUD s)
{
 NODE *temp;
 temp=copynode(s);
 if(first==NULL)
 	first=temp;
 else
 {
 	temp->next=first;
 	first=temp;
 }
 return;
}
void display(NODE *temp)
{
 printf("%s\t",temp->usn);
 printf("%s\t",temp->name);
 printf("%s\t",temp->branch);
 printf("%d\t",temp->sem);
 printf("%llu\n",temp->phno);
}
void deletefront()
{
 NODE *temp;
 int num;
 temp=first;
 if(first==NULL)
 {
 printf("\nList is Empty");
 return;
 }
 if(first->next==NULL)
 	first==NULL;
 else
 	first=first->next;
 printf("\nDeleted node is:");
 display(temp);
 free(temp);
 return;
}

void deleterear()
{
 NODE *cur,*prev;
 cur=first;
 prev=NULL;
 if(first==NULL)
 	{
 	printf("\nList is empty");
 	return;
 	}
 if(first->next==NULL)
 	{
 	display(cur);
 	first=NULL;
 	free(cur);
 	return;
 	}
 while(cur->next!=NULL)
 	{
 	prev=cur;
 	cur=cur->next;
 	}
 prev->next=NULL;
 printf("\nDeleted node is: \n");
 display(cur);
 free(cur);
 return;
}
void displaylist()
{
 NODE *r;
 r=first;
 printf("\nUSN\tName\tBranch\tSem\tPhone\n");
 if(r==NULL)
 	return;
 while(r!=NULL)
 {
 	display(r);
 	r=r->next;
 }
 printf("\n");
}
STUD input()
{
 STUD s;
 printf("\nEnter USN:");
 scanf("%s",s.usn);
 printf("\nEnter name:");
 scanf("%s",s.name);
 printf("\nEnter branch:");
 scanf("%s",s.branch);
 printf("\nEnter Sem:");
 scanf("%d",&s.sem);
 printf("\nEnter phone no.:");
 scanf("%llu",&s.phno);
 return s;
}
int count()
{
 NODE *n;
 int c=0;
 n=first;
 while(n!=NULL)
 {
 	n=n->next;
 	c++;
 }
 return c;
}
int main()
{
 STUD s;
 int i,ch,n;
 first=NULL;
 while(n)
 {
 	printf("\nList Operations:\n");
 	printf("======================\n");
 	printf("1.Create List of n Students by using front insert\n");
 	printf("2.Display status & count nodes\n");
 	printf("3.Perform insertion & deletion at end of SLL\n");
 	printf("4.Perform insertion and deletion at end of SLL\n");
 	printf("5.Exit\n");
 	printf("Enter your choice:\n");
 	scanf("%d",&i);
 	switch(i)
 	{
 	case 1: printf("\n Enter number of students:\n");
 		scanf("%d",&n);
 		for(i=1;i<=n;i++)
 		{
 		printf("\nEnter the details of student :\n");
 		s=input();
 		addfront(s);
 		}
 		break;
 	case 2: if(first==NULL)
 			printf("\nList is empty\n");
 		else
 		{
 			printf("\nNode count=%d\tElemrnts in list are:\n",count());
 			displaylist();
 		}
 		break;
 	case 3: printf("\n1.Insert at End & 2.Delete from End=");
 		scanf("%d",&ch);
 		if(ch==1)
 		{
 			s=input();
 			addrear(s);
 		}
 		else if(ch==2)
 			deleterear();
 		else
 			printf("\nSorry wrong operation:\n");
 		break;
 	case 4: printf("\n1.Insert at End&2.Delete from End=");
 		scanf("%d",&ch);
 		if(ch==1)
 		{
 			s=input();
 			addfront(s);
 		}
 		else if(ch==2)
 			deletefront();
 		else
 			printf("\nSorry wrong operation\n");
 	case 5: exit(0);
 	default:printf("\nInvalid operation");
 	}
 }
 return 0;
}





