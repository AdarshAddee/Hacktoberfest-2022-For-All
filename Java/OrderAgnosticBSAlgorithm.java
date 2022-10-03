//Order Agnostic Binary Search Algorithm for arays in JAVA.
//returns the index of the target.
//Github username: codedmachine111
// Aim: Searches for a target in a given sorted array using binary search algorithm. Solves most problems for searching target in array on leetcode.
// Date: 03/09/2022

import java.util.*;

public class OrderAgnosticBSAlgorithm {
    public static void main(String[] args) {
      int[] arr = {7,6,5,4,3,2,1};
      int key = 6;
      System.out.println(orderAgnosticBinarySearch(arr,key));
  }

  static int binarySearch(int[] arr, int key){
    int start=0;
    int end =arr.length-1;
    while(start <= end){
      int mid = start + (end-start)/2;
      
      if(arr[mid]<key){
        start = mid+1;
      }
      else if(arr[mid]>key){
        end = mid-1;
      }
      else{
        return mid;
      }
    }
    return -1;
  }
  
  static int orderAgnosticBinarySearch(int[] arr, int key){
    
    int start=0;
    int end =arr.length-1;
    boolean isAsc=arr[start] <arr[end];
    while(start <= end){
      int mid = start + (end-start)/2;
      if(arr[mid]==key){
        return mid;
      }
      
      if(isAsc){
        if(arr[mid]>key){
          end = mid-1;
        }
        else{
          start = mid +1;
        }
      }
      else{
        if(arr[mid]>key){
          start = mid+1;
        }
        else{
          end=mid-1;
        }
      }
    }
    return -1;
  }
  
}