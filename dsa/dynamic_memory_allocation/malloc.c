#include<stdio.h>
#include<stdlib.d>
int main()
{
  int i,n;
  printf("Enter the no. of elments :");
  scanf("%d",&n);
  int *ptr=(int*)malloc(sizeof(int));
  if(ptr==NULL)
  {
    printf("Memory not allocated");
    exit(1);
  }
  for(i=0;i<n;i++)
    {
      printf("Enter an integer");
      scanf("%d",ptr+1);
    }
  for(i=0;i<n;i++)
    {
      printf("%d",*(ptr+1));
    }
  return 0;
}
