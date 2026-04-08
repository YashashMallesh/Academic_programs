import java.io.UnsupportedEncodingException;

public class strexmp{
  public static void main(String args[]){
    String str1 = new String();
    System.out.println("Default Constructor"+str1);
    
    String str2 = new String("Hello World!");
    System.out.println("Constructor with string argument"+str2);

    char[] chararray = {'H','e','l','l','o'};
    String str3  = new String(chararray);
    System.out.println("Constructor with Character Array"+str3);

    char[] chararrayoffset = {'H','e','l','l','o',',','W','o','r','l','d'};
    String str4  = new String(chararrayoffset);
    System.out.println("Constructor with Character Array and Offset"+str4);

  }
}
