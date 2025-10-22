#include<stdio.h>
#include<stdlib.h>
int main()
{
  int i,j,rows,cols,**array;
  printf("Enter the no. of rows\n");
  scanf("%d",&rows);

  printf("\nEnter the no. of columns\n");
  scanf("%d",&cols);

  array=(int**)malloc(rows*sizeof(int*));
  if(array==NULL)
  {
    printf("Memory allocation failed");
    exit(1);
  }
  for(i=0;i<rows;i++)
    {
      array[i]=(int)malloc(cols*sizeof(int));
      if(array==NULL)
  {
    printf("Memory allocation failed");
    exit(1);
  }
    }
  printf("\nEnter the elements of array\n");
  for(i=0;i<rows;i++)
    for(i=0;i<cols;i++)
      scanf("%d",&array[i][j]);

  printf("\n The array elements are:\n");
  for(i=0;i<rows;i++)
    {
    for(i=0;i<cols;i++)
      printf("%d",&array[i][j]);
    printf("\n");
    }
}
