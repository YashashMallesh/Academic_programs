//Sorts random numbers from 10 to 100 in tens place.

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;

public class Program2{
  public static void main(String args[]){
    ArrayList<Integer> numbers = new ArrayList<>();
    Random random = new Random();
    while(numbers.size()<10){
      int number = random.nextInt(501)*5;
      if(number%2==0 && number>=10 && number<=100)
        number.add(number);
    }
  System.out.println("Numbers before Sorting");
    for(int number:numbers)
      System.out.println(Number+"\t");
    System.out.println();
    Collections.sort(numbers,new Comparator<Integer>(){
      @Override
      public int Compare(Integer o1,Integer o2){
        int t1 = (o1/10)%10;
        int t2 = (o2/10)%10;
        return Integer.Compare(t1,t2);
      }
    });
    System.out.println("Numbers after Sorting");
    for(int number:numbers){
      System.out.println(number+"\t");
    }
  }
}
