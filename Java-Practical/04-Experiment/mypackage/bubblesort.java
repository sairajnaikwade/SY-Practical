// Source code is decompiled from a .class file using FernFlower decompiler.
package mypackage;

public class bubblesort {
   public bubblesort() {}

   // Bubble sort method
   public void bubbleSort(int[] arr) {
      int n = arr.length;
      for (int i = 0; i < n - 1; i++) {
         for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
               // Swap arr[j] and arr[j + 1]
               int temp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = temp;
            }
         }
      }
   }
}
