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
}
