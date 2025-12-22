import java.util.Scanner;
class Stack{
  private int arr[];
  private int top,size;
  Stack()
  {
    arr=new int[10];
    top=-1;
    size=5;
  }
  public void push(int x)
  {
    if(top==size-1)
      System.out.println("Stack overflow");
    else
    {
      System.out.println("Inserting"+x);
      arr[++top]=x;
    }
  }
  public int pop()
  {
    if(top==-1)
    {
      System.out.println("Stack copy");
      return 0;
    }
    else
      return arr[top--];
  }
  public void printStack()
  {
    for(int i=0; i<=top; i++)
      System.out.println(arr[i]+"");
  }
}
public class DemoStack
{
  public static void main(String[] args)
  {
    int ch;
    Stack s1=new Stack();
    while(true)
      {
        System.out.println("Enter your choice \n 1. Push \n 2. POP \n 3. Display \n 4. Exit");
        Scanner Scan = new Scanner();
        ch=Scan.nextInt();
        switch(ch)
        {
          case 1: System.out.println("Enter Element");
                  int ele=Scan.nextInt();
                  s1.push(ele);
                  break;
          case 2: System.out.println("Popped Element is ");
                  s1.pop();
                  break;
          case 3: s1.printStack();
                  break;
          case 4: System.exit(0);
          default: System.out.println("Wrong open");
        }
      }
Scan.close();
  }
}
