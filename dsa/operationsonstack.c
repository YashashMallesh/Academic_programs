#include<stdio.h>
#include<stdlib.h>
# define MAX 5
int s[MAX];
int top=-1;
void push(int item);
int pop();
void palindrome();
void display();
void main()
{
  int choice, item;
  while(1)
    {
      printf("\n\n\n----Menu----");
      printf("\n_1.Push an Element to Stack and Overflow demo");
      printf("\n_2.Pop an element from stack and underflow demo");
      printf("\n_3.Palindrome demo");
      printf("\n_4.Display");
      printf("\n_5.Exit");
      printf("\nEnter your choice");
    }
}
