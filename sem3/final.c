// Min-Heap data structure in C
#include <stdio.h>
// int size = 0;

enum heapType { minHeap, maxHeap };

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int array[][2], int size, int i, int col, int heapType) {
  if (size == 1) {

    printf("size: %d ,i: %d, col: %d, heaptype; %d", size, i, col, heapType);
    printf("Single element in the heap");
  } else {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (heapType == 0) {
      if (l < size && array[l][col] < array[smallest][col])
        smallest = l;
      if (r < size && array[r][col] < array[smallest][col])
        smallest = r;
    } else {
      if (l < size && array[l][col] > array[smallest][col])
        smallest = l;
      if (r < size && array[r][col] > array[smallest][col])
        smallest = r;
    }
    if (smallest != i) {
      swap(&array[i][0], &array[smallest][0]);
      swap(&array[i][1], &array[smallest][1]);
      heapify(array, size, smallest, col, heapType);
    }
  }
}
void insert(int array[][2], int *size, int newNum1, int newNum2, int col,
            int heapType) {
  if (*size == 0) {
    array[0][0] = newNum1;
    array[0][1] = newNum2;
    *size += 1;
    printf("increased %d", *size);
  } else {
    array[*size][0] = newNum1;
    array[*size][1] = newNum2;
    *size += 1;
    for (int i = *size / 2 - 1; i >= 0; i--) {
      heapify(array, *size, i, col, heapType);
    }
  }
}
void deleteRoot(int array[][2], int *size, int num, int col, int heapType) {
  int i;
  for (i = 0; i < *size; i++) {
    if (num == array[i][col])
      break;
  }

  swap(&array[i][0], &array[*size - 1][0]);
  swap(&array[i][1], &array[*size - 1][1]);
  *size -= 1;
  for (int i = *size / 2 - 1; i >= 0; i--) {
    heapify(array, *size, i, col, heapType);
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
void heapSort(int arr[][2], int n, int col, int heapType) {
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i, col, heapType);
  }
  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0][0], &arr[i][0]);
    swap(&arr[0][1], &arr[i][1]);

    // Heapify root element to get highest element at root again
    heapify(arr, i, 0, col, heapType);
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

  heapSort(intervels, intervel_size, 0, maxHeap);

  int laptop_queue[10][2];
  int laptop_queue_size = 0;
  int laptop_needed = 0;

  printf("Intervel -> \n");
  print2dArray(intervels, 20);
  printf("Intervel -< \n");
  printf("intervel_size %d\n", intervel_size);

  for (int i = 0; i < intervel_size; i++) {
    printf("loop : %d", i);
    if (laptop_queue_size > 0 && laptop_queue[0][1] <= intervels[i][0]) {
      printf("element removed %d", laptop_queue[0][1]);
      deleteRoot(laptop_queue, &laptop_queue_size, laptop_queue[0][1], 1,
                 minHeap);
    }
    printf("pushing %d", intervels[i][1]);
    insert(laptop_queue, &laptop_queue_size, intervels[i][0], intervels[i][1],
           1, minHeap);
    // laptop_needed =
    //    laptop_needed < laptop_queue_size ? laptop_queue_size : laptop_needed;

    printf("laptop_queue-> \n");
    printf("laptop_queue_size %d\n", laptop_queue_size);
    print2dArray(laptop_queue, laptop_queue_size);
    printf("laptop_queue -< \n");
  }

  printf("laptop needed: %d", laptop_queue_size);
}
