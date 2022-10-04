//Insertion Sort algorithm for arrays in JAVA.
// Github username: codedmachine111
// Aim: Sorts given array in ascending order. Solves a few leetcode problems including sorting algorithm.
// Date: 03/09/2022

import java.util.*;

public class InsertionSortAlgorithm {
    public static void main(String[] args) {
    int [] arr = {1,4,5,2,45,6};
    int [] arr2 = {1,2,3,4,5,6,7,8};
    insertionSort(arr);
    System.out.println(Arrays.toString(arr));
  }
  static void swap(int[] arr, int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
  }
  
  static void insertionSort(int[] arr){
    for(int i=0; i< arr.length -1; i++){
      for(int j=i+1; j>0; j--){
        if(arr[j]<arr[j-1]){
          swap(arr,j,j-1);
        }
      }
    }
  }
}