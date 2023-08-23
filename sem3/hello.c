// Min-Heap data structure in C
#include <stdio.h>
int size = 0;
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int array[], int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] < array[smallest])
      smallest = l;
    if (r < size && array[r] < array[smallest])
      smallest = r;
    if (smallest != i) {
      swap(&array[i], &array[smallest]);
      heapify(array, size, smallest);
    }
  }
}
void insert(int array[], int newNum) {
  if (size == 0) {
    array[0] = newNum;
    size += 1;
  } else {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(array, size, i);
    }
  }
}
void deleteRoot(int array[], int num) {
  int i;
  for (i = 0; i < size; i++) {
    if (num == array[i])
      break;
  }



  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
void print2dArray(int array[][2], int size) {
  printf("{");
  for (int i = 0; i < size; ++i)
    printf("{%d,%d}, ", array[i][0], array[i][1]);
  printf("}\n");
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



int main() {

  int intervels[7][2] = {{0, 2}, {1, 4},  {4, 6}, {0, 4},
                         {7, 8}, {9, 11}, {3, 10}};

  int intervel_size = 7;
  bubbleSort(intervels, intervel_size);

  int laptop_queue[10];
  int laptop_needed = 0;
  print2dArray(intervels, intervel_size);

  for (int i = 0; i < intervel_size; i++) {
    if (size > 0 && laptop_queue[0] <= intervels[i][0]) {
      deleteRoot(laptop_queue, size);
    }
    insert(laptop_queue, intervels[i][1]);
    laptop_needed = laptop_needed < size ? size : laptop_needed;
  }
  printArray(laptop_queue, size);

  printf("laptop needed: %d", laptop_needed);
}
