//Types of string comparison, char extraction and string modification methods.

import java.util.*;
publlc class strexmp{
  public static void main(String args[]){
    String str = "Hello World";
    //Character extraction methods:
    System.out.println("Char at index 0:" + str.charAt(0) 
                       + "\n First occurrence of 'l':" + str.indexOf('l')
                      + "\n Substring from index 0 to 5" + str.substring(0,5));
    //String comparison methods:
    String str1  = "Hello World!";
    String str2 = "hello world!";
    System.out.println("Equals ignore case:" + str1.equalsIgnoreCase(str2) 
                       + "Starts with 'Hello':" + str1.startsWith("Hello")
                      + "Ends with '!':" + str1.endsWith("!"));
    //String search methods:
    System.out.println("Conatins 'World':" + str1.contains("World") 
                       + "Index of '!':" + str1.indexOf("!")
                      + "Last index of 'l':" + str1.lastIndexOf("l"));
    //String modification methods:
    System.out.println("Upper and lower case:" + str2.toUpper() + "," + str1.toLower() 
                       + "Trim " + "Hello World!".trim()
                      + "Replace 'World' with 'Java':" + str1.replace("World","Java")
                      + "Concatinate ' and goodbye':" + str1.concat(" and goodbye"));
  }
}
