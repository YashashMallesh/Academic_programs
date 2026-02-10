#include<stdio.h>
#include<stdlib.h>
void main()
{
  int *ptr;
  int i,n;
  printf("Enter the no. of integers:\n");
  scanf("%d",&n);
  ptr = (int*)calloc(n*sizeof(int));
  if(ptr==NULL)
  {
    printf("Memory not allocated");
    exit(1);
  }
  for(i=0;i<n;i++)
    {
      printf("Enter The Integers\n");
      scanf("%d",ptr+i);
    }
  for(i=0;i<n;i++)
    {
      printf("%d",*(ptr+i));
    }
  return(0);
}
