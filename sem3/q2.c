#include <stdio.h>
#include <stdlib.h>

 

// Merge two sorted arrays
int *mergeArrays(int *arr1, int size1, int *arr2, int size2, int *mergedSize) {
  int *merged = (int *)malloc(sizeof(int) * (size1 + size2));
  int i = 0, j = 0, k = 0;

 

  while (i < size1 && j < size2) {
    if (arr1[i] < arr2[j]) {
      merged[k++] = arr1[i++];
    } else {
      merged[k++] = arr2[j++];
    }
  }

 

  while (i < size1) {
    merged[k++] = arr1[i++];
  }

 

  while (j < size2) {
    merged[k++] = arr2[j++];
  }

 

  *mergedSize = k;
  return merged;
}

 

int main() {
  int k; // Number of arrays
  printf("Enter the number of sorted arrays: ");
  scanf("%d", &k);

 

  int **arrays = (int **)malloc(sizeof(int *) * k);
  int *arraySizes = (int *)malloc(sizeof(int) * k);

  for (int i = 0; i < k; i++) {
    int size;
    printf("Enter the size of array %d: ", i + 1);
    scanf("%d", &size);
    arraySizes[i] = size;

    arrays[i] = (int *)malloc(sizeof(int) * size);
    printf("Enter the elements of array %d in sorted order: ", i + 1);
    for (int j = 0; j < size; j++) {
      scanf("%d", &arrays[i][j]);
    }
  }

  // Merge the sorted arrays
  int mergedSize = 0;
  int *mergedArray = NULL;

  for (int i = 0; i < k; i++) {
    mergedArray = mergeArrays(mergedArray, mergedSize, arrays[i], arraySizes[i], &mergedSize);
    free(arrays[i]); // Free individual arrays as they are merged
  }

  printf("Merged Sorted Array: ");
  for (int i = 0; i < mergedSize; i++) {
    printf("%d ", mergedArray[i]);
  }
  printf("\n");

  // Clean up memory
  free(arrays);
  free(arraySizes);
  free(mergedArray);

 

  return 0;
}
