// https://www.programiz.com/dsa/heap-data-structure
#include <stdio.h>
#define HEAP_MEM_SIZE 100

int heap[HEAP_MEM_SIZE], heapSize = 0;

void swap(int *a, int *b) {

  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void heapify(int arr[], int size, int i) {

  // no need to heapify if there is only one element
  if (size == 1) {
    printf("only one element");
  } else {

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && heap[l] > heap[largest]) {
      largest = l;
    }
    if (r < size && heap[r] > heap[largest]) {
      largest = r;
    }
    if (largest != i) {
      swap(&arr[i], &heap[largest]);
    }
  }
}

void insert(int element) {

  if (heapSize == 0) {
    heap[0] = element;
    heapSize++;
  } else {
    heap[heapSize] = element;
    heapSize++;
    for (int i = 1; i <= heapSize; i++) {
    }
  }
}

int main(int argc, char *argv[]) { return 0; }
