import java.util.ArrayList;
import java.util.List;

class Student{
  private String name;
  private int age;
  public Student(String name,int age){
    this.name = name;
    this.age = age;
  }
  public String getname(){
    return name;
  }
  public String getage(){
    return age;
  }
  @Override
  public String toString(){
    return "Student{"+"name'"+'\''+",age="+age+"}";
  }
}
public class storinguserdefinedclasses{
  public static void main(String args[]){
    List<Student> student = new ArrayList<>();
    student.add(new Student("Alice",20));
    student.add(new Student("Bob",22));
    student.add(new Student("Charlie",25));
    for(Student Student: student){
      System.out.println(student);
    }
  }
}
