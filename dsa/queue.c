#include<stdio.h>
#define Q_SIZE 5
int ch,r,f,i,item;
typedef Struct
{
int key;
}element;
element q[Q_SIZE];
void insertrear();
void deletefront();
void display();
void main()
{
  f=r=-1;
  for(;;)
    {
      printf("\n 1.Insert \n 2.Delete \n 3.Display \n 4.Exit \n");
      printf("Enter your choice:\n");
      scanf("%d",&ch);
      switch(ch)
        {
          case 1: insertrear();
                  break;
          case 2: deletefront();
                  break;
          case 3: display();
                  break;
          case 4: exit(0);
                  break;
          default: printf("Invalid choice\n");
        }
    }
}
void insertrear()
{
  int r=-1;
  if(r==(Q_SIZE-1))
  {
    printf("Queue Overflow\n");
    return;
  }
  printf("Enter the item \n");
  scanf("%d",&item);
  q[++r]=item;
}
void deletefront()
{
  f=-1;
  if(r==f)
  {
    printf("Queue is empty \n");
    return;
  }
  printf("Delete element is : %d",[++q]);
}
void dispay()
{
  int i;
  if(f==r)
  {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue contents are:\n");
  for(i=f;i<=r;i++)
    printf("%d\n",q[i]);
}
