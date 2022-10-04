//Selection SOrt algorithm for arrays in JAVA
//Github username: codedmachine111
// Aim: Sorts given array in ascending order. Solves a few leetcode problems including sorting algorithm.
// Date: 03/09/2022

import java.util.*;

public class SelectionSortAlgorithm {
    public static void main(String[] args) {
    int [] arr = {1,4,5,2,45,6};
    int [] arr2 = {1,2,3,4,5,6,7,8};
    selectionSort(arr);
    System.out.println(Arrays.toString(arr));
  }
  static int getMaxIndex(int[] arr, int start, int end){
    int max =start;
    for(int i=start; i<=end; i++){
      if(arr[i]>arr[max]){
        max = i;
      }
    }
    return max;
  }
  static void swap(int[] arr, int x, int y){
    int temp = arr[x];
    arr[x]=arr[y];
    arr[y]=temp;
  }
  static void selectionSort(int[] arr){
    for(int i=0; i<arr.length; i++){
      int last = arr.length -1 -i;
      int maxIndex =getMaxIndex(arr,0,last);
      swap(arr,maxIndex,last);
    }
  }
}