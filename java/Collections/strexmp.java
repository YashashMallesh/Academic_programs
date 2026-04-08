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

    byte[] bytearray = {72,101,108,108,111};
    String str5  = new String(bytearray);
    System.out.println("Constructor with Byte Array"+str5);
    try{
    byte[] bytearraycharset = {72,101,108,108,111};
    String str6  = new String(bytearraycharset,"UTF-8");
    System.out.println("Constructor with Byte Array and charset"+str6);
      
    byte[] bytearrayoffset = {72,101,108,108,111,32,87,111,114,108,100};
    String str7  = new String(bytearrayoffset,6,8);
    System.out.println("Constructor with Byte Array and Offset"+str7);

    byte[] bytearrayoffsetcharset = {72,101,108,108,111,32,87,111,114,108,100};
    String str8  = new String(bytearrayoffsetcharset,6,8,"UTF-8");
    System.out.println("Constructor with Byte Array, Offset, Length and Charset"+str8);
    }catch(UnsupportedEncodingException e){
      System.out.println("Error:Unsupprted Encoding Exception.");
    }
  }
}
