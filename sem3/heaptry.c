#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int heap[100], heapSize = 0;

void initHeap() { heapSize = 0; }

void printArray(int arr[], int size) {
  printf("\n > ");
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

void insert(int element) {
  heapSize++;
  heap[heapSize] = element;

  int currentPos = heapSize;
  while (heap[currentPos / 2] > element) {
    heap[currentPos] = heap[currentPos / 2];
    currentPos /= 2;
  }
  heap[currentPos] = element;
}

int main(int argc, char *argv[7]) {
  initHeap();

  int isize = 10;
  int elements[] = {
      30, 90, 14, 11, 11, 16, 37, 16, 24, 18,
  };

  printArray(elements, 10);

  for (int i = 0; i < 10; i++) {
    insert(elements[i]);
  }

  printArray(heap, 10);
  printf("%d", heapSize);

  return 0;
}
