#include <stdio.h>

void swap2d(int arr[][2], int a, int b) {
  int temp[2];
  temp[0] = arr[a][0];
  temp[1] = arr[a][1];

  arr[a][0] = arr[b][0];
  arr[a][1] = arr[b][1];

  arr[b][0] = temp[0];
  arr[b][1] = temp[1];
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int arr[][2], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j][0] > arr[j + 1][0]) {
        swap(&arr[j][0], &arr[j + 1][0]);
        swap(&arr[j][1], &arr[j + 1][1]);
      }
    }
  }
}

void sort_double_array(int A[][2], int n) {
  int i, j;
  for (i = 1; i < n; i++) { /*swap A[i] left into correct position */
    for (j = i - 1; j >= 0 && A[j + 1] < A[j]; j--) {
      swap2d(A, j, j + 1);
    }
  }
}
void print2dArray(int array[][2], int size) {
  printf("{");
  for (int i = 0; i < size; ++i)
    printf("{%d,%d}, ", array[i][0], array[i][1]);
  printf("}\n");
}

/*
int main() {
  int a[3][2] = {{1, 2}, {5, 4}, {3, 4}};
  print2dArray(a, 3);
  sort_double_array(a, 3);
  print2dArray(a, 3);

  return 0;
}
*/

int main() {
  int intervals[][2] = {{0, 2}, {1, 4},  {4, 6}, {0, 4},
                        {7, 8}, {9, 11}, {3, 10}};
  int numIntervals = sizeof(intervals) / sizeof(intervals[0]);

  bubbleSort(intervals, numIntervals);

  print2dArray(intervals, numIntervals);

  printf("\n");

  return 0;
}
