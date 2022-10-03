//JAVA program to generate fibonacci series using class
//Github username: codedmachine111
// Aim: Displays the Fibonacci Series for a given number.
// Date: 03/09/2022
import java.util.*;

public class FibonacciSeries{
  public static void main(String[] args){
      Scanner input = new Scanner(System.in);
      
    int n = input.nextInt();
    int a=0, b=1, count=0;
    if(n==1 || n==0){
      System.out.println(n);
    }
    while (count < n) {
            System.out.print(a + " ");
            // Swap
            int c = a + b;
            a = b;
            b = c;
            count ++;
        }
    }
}