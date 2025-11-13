#include<stdio.h>
#include<calloc.h>
#include<math.h>
struct Node
{
int cf,px,py,pz;
int flag;
struct node *link;
};
typedef struct node NODE;
NODE* getnode();
{
p=(NODE*)malloc(sizeof(NODE));
if(p==NULL)
{
printf("\nInsufficient Memory");
 exit(0); 
}
  return p;
}
void display()
{
NODE *temp;
  if(head->link==head)
  {
    printf("\nPolynomial does not exist\n");
    return;
  }
temp=head->link;
  printf("\n");
  while(temp!=head)
    {
      printf("%d x^%d y^%d z^%d",temp->cf,temp->px,temp->py,temp->pz);
        if(temp->link!=head)
          printf("+");
      temp=temp->link;
    }
  printf("\n");
}
NODE* insert_rear(int cf,int x,int y,int z,NODE *head)
{
  NODE *temp, *cur;
  temp=getnode();
  temp->cf=cf;
  temp->px=px;
  temp->py=py;
  temp->pz=pz;
  cur=head->link;
  while(cur->link!=head)
      cur=cur->link;
  cur->link=temp;
  temp->link=head;
  return head;
    }
NODE* read_poly(NODE *head)
{
  int px,py,pz,cf,ch;
  printf("\n Enter Coeff\n");
  scanf("%d",&ch);
  printf("\n Enter x,,y,z power(0-indicate no term):");
  scanf("%d %d %d",&px,&py,&pz);
  head=insert_rear(cf,px,py,pz,head);
  printf("\nIf you wish to continue press 1 otherwise 0:");
  scanf("%d",&ch);
  while(ch!=0)
    {
      printf("\nEnter Coeff");
      scanf("%d",&cf);
      printf("\n Enter x,,y,z power(0-indicate no term):");
      scanf("%d %d %d",&px,&py,&pz);
      head=insert_rear(cf,px,py,pz,head);
      printf("\nIf you wish to continue press 1 otherwise 0:");
      scanf("%d",&ch);
    }
  return head;
}
NODE* add_poly(NODE *h1,NODE *h2,NODE *h3)
{
 NODE *p1,*p2;
 int x1,x2,y1,y2,z1,z2,cf1,cf2,cf;
 p1=h1->link;
 while(p1!=h1)
  {
   x1=p1->px;
   y1=p1->py;
   z1=p1->pz;
   cf1=p1->cf;
   p2=h2->link;
  }
 while(p2!=h2)
  {
   x2=p2->px;
   y2=p2->py;
   z2=p2->pz
   cf2=p2->cf;
   if(x1==x2&&y1==y2&&z1==z2)
    break;
   p2=p2->link;
  }
 if(p2!=h2)
 {
  cf=cf1+cf2;
  p2->flag=1;
  if(cf!=0)
   h3=insert_rear(cf,x1,y1=1,h3)
 }
  else
  h3=insert_rear(cf1,x1,y1,z1,h3)
  p1=p1->link;
}
p2=p2->link;
while(p2!=h2)
 {
  if(p2->flag==0)
   h3=insert_rear(p2->cf,p2->px,p2->py,p2->pz,h3)
  p2=p2->link;
 }
return h3;
}
void evaluate()
{
 NODE *head;
 int x,y,z;
 float result=0.0;
 head=h1;
 printf("\nEnter x,y,z terms to evaluate");
 scanf("%d %d %d",&x,&y,&z);
 while(h1->link!=head)
  {
   result=result+(h1->cf*pow(x,h1->px)*pow(y,h1->py)*pow(z,h1->pz));
   h1=h1->link;
  }
 result=result+(h1->cf*pow(x,h1->px)*pow(y,h1->py)*pow(z,h1->pz));
 printf("\nPolynomial result is %f",result);
}
void main()
{
 NODE *h1,*x,*y,*z;
 int ch;
 clrscr();
 h1=getnode();
 x=getnode();
 y=getnode();
 z=getnode();
 h1->link=h1;
 x->link=x;
 y->link=y;
 z->link=z;
 while(1)
  {
   printf("\n1.Evaluate Polynomial \n2.Add two polynomial \n3.Exit\n");
   printf("Enter your choice:");
   scanf("%d",&ch);
   switch(ch)
    {
     case 1:printf("\nEnter polynomial to evaluate:\n");
            h1=read_poly(h1);
            display(h1);
            evaluate(h1);
            break;
     case 2:printf("\nEnter first polynomial:");
            x=read_poly(x);
            printf("\nEnter second Polynomial:");
            y=read_poly(y);
            z=add_poly(x,y,z);
            printf("\nFirst Polynomial");
            display(x);
            printf("\nSecond Polynomial");
            display(y);
            printf("\nThe sum of two polynomials: ");
            display(z);
            break;
     case 3:exit(0);
            break;
     default:printf("\nInvalid Entry\n");
             break;
    }
   getch();
  }
}
