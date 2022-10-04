//BubbleSortAlgorithm for arrays in JAVA.
// Github username: codedmachine111
// Aim: Sorts given array in ascending order. Solves a few leetcode problems including sorting algorithm.
// Date: 03/09/2022

import java.util.*;

public class BubbleSortAlgorithm {
    public static void main(String[] args) {
    int [] arr = {1,5,3,6,7,4,8};
    int [] arr2 = {1,2,3,4,5,6,7,8};
    bubbleSort(arr);
    System.out.println(Arrays.toString(arr2));
  }
  
  static void bubbleSort(int[] arr){
    boolean isSorted=false;
    for(int i=0; i<arr.length -1; i++){
      isSorted=true;
      for(int j=0; j< arr.length -1-i; j++){
        if(arr[j]>arr[j+1]){
          int temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
          isSorted=false;
        }
      }
      if(isSorted){
        return;
      }
    }
  }
}