#include<stdio.h>
#include<stdlib.h>
#include<string.h>
Struct Day
{
  char *name;
  int date;
  char *activity;
};
Struct Day week[7];
void main()
{
  printf("Create and read a calender");
  read();
  printf("Display Calender");
  display();
}
void create()
{
  for(int i=0;i<7;i++)
  {
    week[i].name = (char*)malloc(20*size of (char));
    week[i].activity = (char*)malloc(100*size of(char));
    printf("Enter the name of the day %d",i+1);
    scanf("%s",week[i].name);
    printf("Enter the date of the day %d",i+1);
    scanf("%d",week[i].date);
    printf("Enter the activity for day %d",i+1);
    getchar();
    fgets(week[i].activity,100,stdlin);
  }
  void read()
{
  create();
}
  void display()
{
  printf("\nDay\tDate\tActivity\n");
  for(int i=0;i<7;i++)
    printf("%s\t%d|t%s",week[i].day,week[i].date,week[i].activity);
}
}
