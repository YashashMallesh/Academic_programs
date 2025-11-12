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

