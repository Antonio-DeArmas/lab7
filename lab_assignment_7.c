#include <stdio.h>

void bubbleSort(int original[], int n, int sorted[], int swaps[][2], int *totalSwaps);
void selectionSort(int original[], int n, int sorted[], int swaps[][2], int *totalSwaps);

int main() {
  int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
  int n = 9;

  int totalSwaps = 0;
  int swaps[n * n][2]; 
  int sorted[n];

  printf("array1 bubblesort:\n");
  bubbleSort(arr1, n, sorted, swaps, &totalSwaps);
  totalSwaps = 0;
  printf("array2 bubblesort:\n");
  bubbleSort(arr2, n, sorted, swaps, &totalSwaps);
  totalSwaps = 0;
  printf("array1 selectionsort:\n");
  selectionSort(arr1, n, sorted, swaps, &totalSwaps);
  totalSwaps = 0;
  printf("array2 selectionsort:\n");
  selectionSort(arr2, n, sorted, swaps, &totalSwaps);
  
  return 0;
}
void bubbleSort(int original[], int n, int sorted[], int swaps[][2], int *totalSwaps){
  for (int i = 0; i < n; i++) 
    sorted[i] = original[i];

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (sorted[j] > sorted[j + 1]) {
        int temp = sorted[j];
        sorted[j] = sorted[j + 1];
        sorted[j + 1] = temp;

        swaps[*totalSwaps][0] = sorted[j]; 
        swaps[*totalSwaps][1] = sorted[j + 1]; 
        (*totalSwaps)++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int swapsCount = 0;
    for (int j = 0; j < *totalSwaps; j++) {
      if (swaps[j][0] == sorted[i] || swaps[j][1] == sorted[i])
        swapsCount++;
    }
    printf("%d: %d\n", sorted[i], swapsCount);
  }
  printf("%d\n", *totalSwaps);
}
void selectionSort(int original[], int n, int sorted[], int swaps[][2], int *totalSwaps){
  for (int i = 0; i < n; i++)
    sorted[i] = original[i];

  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (sorted[j] < sorted[minIndex])
        minIndex = j;
    }
    if (minIndex != i) {
      int temp = sorted[i];
      sorted[i] = sorted[minIndex];
      sorted[minIndex] = temp;

      swaps[*totalSwaps][0] = sorted[i];
      swaps[*totalSwaps][1] = sorted[minIndex];
      (*totalSwaps)++;
    }
  }
  for (int i = 0; i < n; i++) {
    int swapsCount = 0;
    for (int j = 0; j < *totalSwaps; j++) {
      if (swaps[j][0] == sorted[i] || swaps[j][1] == sorted[i])
        swapsCount++;
    }
    printf("%d: %d\n", sorted[i], swapsCount);
  }
  printf("%d\n", *totalSwaps);
}
