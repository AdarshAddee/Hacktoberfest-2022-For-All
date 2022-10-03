// Github username: satrio-pamungkas
// Aim: Bubble Sort with choice (asc or desc) 
// Date: Oct 3, 2022

// start coding
import java.util.Scanner;

public class BubbleSortAlgorithm {
    private final int[] items = {27, 64, 4, 7, 15, 89, 22};

    public static void main(String[] args) {
        BubbleSortAlgorithm bubbleSort = new BubbleSortAlgorithm();
        Scanner sortingType = new Scanner(System.in);
        int[] sortedArray;
        
        System.out.println("ASC or DESC ?");
        String inputType = sortingType.nextLine();
        System.out.println(inputType);
        
        if (inputType.equals("ASC")) {
            sortedArray = bubbleSort.sortAscending(bubbleSort.items);
        } else if (inputType.equals("DESC")) {
            sortedArray = bubbleSort.sortDescending(bubbleSort.items);
        } else {
            System.out.println("Out of option");
            return;
        }
        

        for (int i=0; i < sortedArray.length; i++) {
            System.out.println(sortedArray[i] + " ");
        }
    }

    private int[] sortAscending(int[] list) {
        int temp;

        for (int i = 0; i <= list.length - 2; i++) {
            for (int j = 0; j <= list.length - 2; j++) {
               if (list[j] > list[j + 1]) {
                  temp = list[j + 1];
                  list[j + 1] = list[j];
                  list[j] = temp;
               }
            }
        }

        return list;
    }
    
    private int[] sortDescending(int[] list) {
        int temp;
        
        for (int i = 0; i <= list.length - 2; i++) {
            for (int j = 0; j <= list.length - 2; j++) {
               if (list[j] < list[j + 1]) {
                  temp = list[j + 1];
                  list[j + 1] = list[j];
                  list[j] = temp;
               }
            }
        }

        return list;
    }
}
