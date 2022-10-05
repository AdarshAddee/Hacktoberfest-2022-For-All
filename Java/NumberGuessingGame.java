// Number guessing game in JAVA 
//Github username: codedmachine111
// Aim: Cures boredom when you try to guess a number between 1 to 100 in 5 tries.
// Date: 03/09/2022

import java.util.*;

public class NumberGuessingGame {
    public static void main(String[] args) {
      game();
  }
  static void game()
    {
      Scanner sc = new Scanner(System.in);
      // genrate random number
      int number = 1 + (int)(100* Math.random());
      //number of tries
      int tries = 5;
      int i, guess;
      System.out.println("Guess a number between 1 to 100 in 5 tries.");

      for (i = 0; i < tries; i++) {
        System.out.println("Guess the number");
        guess = sc.nextInt();
        if (number == guess) {
            System.out.println("Great! You guessed it!");
            break;
            }
      else if (number > guess && i != tries - 1) {
            System.out.println("The number is greater than "+ guess);
            }
      else if (number < guess && i != tries - 1) {
            System.out.println("The number is less than "+ guess);
            }
        }
      if (i == tries) {
            System.out.println("Oops! The number was "+ number); 
        }
    }
}