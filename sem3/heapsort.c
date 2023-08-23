// Heap Sort in C

#include <math.h>
#include <stdio.h>

// Function to swap the the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int i) {
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);

    // Heapify root element to get highest element at root again
    heapify(arr, i, 0);
  }
}

// Print an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}
void putSpaces(int x) {
  for (int i = 0; i < x; i++) {
    printf(" ");
  }
}

void printHeap(int arr[], int n) {
  printf("heap rep");

  int depth = log2(n + 1);
  int k = 0;
  printf("%d\n\n", arr[0]);
  for (int i = 0; k < n; i++) {
    for (int j = 0; j <= pow(2, i); j++) {
      // printf("d:%d", depth);
      int spaces = pow(2, depth) - 1;

      if (arr[k] > 10) {
        spaces--;
      }
      putSpaces(spaces);

      if (j % 2 == 0) {
        printf("%d", arr[k]);
        k++;
      } else {
        putSpaces(1);
      }
      if (k == n) {
        break;
      }
    }

    depth--;
    printf("\n");
  }

  printf("\n");
}

// Driver code
int main() {
  int arr[] = {1, 12, 9, 5, 6, 10, 23, 56, 12, 78, 24, 26, 95};
  int n = sizeof(arr) / sizeof(arr[0]);

  printHeap(arr, n);

  heapSort(arr, n);

  printf("Sorted array is \n");
  printArray(arr, n);
}

/*
*

 *
* *

   *
 *   *
* * * *


       *
   *       *
 *   *   *   *
* * * * * * * *

2^3 - 1

*/
