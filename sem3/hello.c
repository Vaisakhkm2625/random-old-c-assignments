// Min-Heap data structure in C
#include <stdio.h>
// int size = 0;

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int array[][2], int size, int i, int col) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l][col] < array[smallest][col])
      smallest = l;
    if (r < size && array[r][col] < array[smallest][col])
      smallest = r;
    if (smallest != i) {
      swap(&array[i][0], &array[smallest][0]);
      swap(&array[i][1], &array[smallest][1]);
      heapify(array, size, smallest, col);
    }
  }
}
void insert(int array[][2], int *size, int newNum1, int newNum2, int col) {
  if (*size == 0) {
    array[0][0] = newNum1;
    array[0][1] = newNum2;
    *size += 1;
  } else {
    array[*size][0] = newNum1;
    array[*size][1] = newNum2;
    size += 1;
    for (int i = *size / 2 - 1; i >= 0; i--) {
      heapify(array, *size, i, col);
    }
  }
}
void deleteRoot(int array[][2], int *size, int num, int col) {
  int i;
  for (i = 0; i < *size; i++) {
    if (num == array[i][col])
      break;
  }

  swap(&array[i][0], &array[*size - 1][0]);
  swap(&array[i][1], &array[*size - 1][1]);
  *size -= 1;
  for (int i = *size / 2 - 1; i >= 0; i--) {
    heapify(array, *size, i, col);
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
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
void heapSort(int arr[][2], int n, int col) {
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i, col);
  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0][0], &arr[i][0]);
    swap(&arr[0][1], &arr[i][1]);

    // Heapify root element to get highest element at root again
    heapify(arr, i, 0, col);
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

  int intervels[20][2];
  int intervel_size = 7;

  printf("How many intervels:");
  scanf("%d", &intervel_size);
  printf("Enter intervels: (give start,end)\n");

  // int intervels[7][2] = {{0, 2}, {1, 4},  {4, 6}, {0, 4},
  //                        {7, 8}, {9, 11}, {3, 10}};

  for (int i = 0; i < intervel_size; i++) {
    scanf("%d,%d", &intervels[i][0], &intervels[i][1]);
  }

  printf("before heap sort");
  print2dArray(intervels, intervel_size);
  // heapSort(intervels, intervel_size, 0);
  // bubbleSort(intervels, intervel_size);
  print2dArray(intervels, intervel_size);
  printf("after heap sort");

  int laptop_queue[10][2];
  int laptop_queue_size = 0;
  int laptop_needed = 0;
  print2dArray(intervels, intervel_size);

  for (int i = 0; i < intervel_size; i++) {
    if (laptop_queue_size > 0 && laptop_queue[0][1] <= intervels[i][0]) {
      deleteRoot(laptop_queue, &laptop_queue_size, laptop_queue[0][1], 0);
    }
    insert(laptop_queue, &laptop_queue_size, intervels[i][0], intervels[i][1],
           1);
    laptop_needed =
        laptop_needed < laptop_queue_size ? laptop_queue_size : laptop_needed;
  }

  print2dArray(laptop_queue, laptop_queue_size);

  printf("laptop needed: %d", laptop_needed);
}
