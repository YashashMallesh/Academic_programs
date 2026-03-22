import java.util.*;
class Arraylist{
public static void main(String args[]){
  ArrayList<Integer> al = new ArrayList<>();
  al.add(5);
  al.add(2);
  al.add(0);
  al.add(1);
  al.add(9);
  System.out.println("Initial Arraylist"+al);
  al.remove(2);
  System.out.println("Arraylist after removing an element"+al);
  Collections.sort(al);
  System.out.println("Sorted Arraylist"+al);
  Integer[] arr = al.toArray(new Intger[0]);
  System.out.println("Array"+Arrays.toString(array));
}
}
