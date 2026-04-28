import java.lang.*;

public class strbuffer{
  public static void main(String args[]){
    StringBuffer sb = new StringBuffer("Hello World!");
    System.out.println("Length:"+sb.length());
    System.out.println("Capacity:"sb.capacity());

    sb.ensureCapacity(10);
    System.out.println("Ensure Capacity of 30:"+sb.capacity);
    sb.insert(5,"Java");
    System.out.println("Insert 'Java' at index 5:"+sb);
    sb.delete(5,10);
    System.out.println("Delete from index 5 to 10:"+sb);
    sb.reverse();
    System.out.println("Reverse:"+sb);
    sb.append(" and Goodbye");
    System.out.println("Appending ' and Goodbye':"+sb);
    sb.deleteCharAt(5);
    System.out.println("Deleting char at 5:"+sb);
    sb.replace(0,5,"Hi");
    System.out.println("Replace 'Hello' with 'Hi':"+sb);
  }
}
