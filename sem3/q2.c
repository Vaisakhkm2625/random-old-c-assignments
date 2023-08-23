#include <stdio.h>
#include <stdlib.h>

int* mergeArrays(int* arrays[], int sizes[], int numArrays, int* resultSize) {
    // Calculate the total number of elements
    int totalSize = 0;
    for (int i = 0; i < numArrays; i++) {
        totalSize += sizes[i];
    }

    // Allocate memory for the merged array
    int* merged = (int*)malloc(totalSize * sizeof(int));

    // Merge the arrays
    int idx[numArrays];
    for (int i = 0; i < numArrays; i++) {
        idx[i] = 0;
    }

    int mergedIdx = 0;
    while (mergedIdx < totalSize) {
        int minValue = _INT_MAX_;
        int minArrayIdx = -1;

        for (int i = 0; i < numArrays; i++) {
            if (idx[i] < sizes[i] && arrays[i][idx[i]] < minValue) {
                minValue = arrays[i][idx[i]];
                minArrayIdx = i;
            }
        }

        if (minArrayIdx == -1) {
            break; // All arrays are fully merged
        }

        merged[mergedIdx++] = minValue;
        idx[minArrayIdx]++;
    }

    *resultSize = mergedIdx;
    return merged;
}

int main() {
    int arr1[] = {-4, 1, 2, 5};
    int arr2[] = {-9, 8, 10};
    int* arrays[] = {arr1, arr2};
    int sizes[] = {4, 3};
    int numArrays = sizeof(arrays) / sizeof(arrays[0]);

    int resultSize;
    int* merged = mergeArrays(arrays, sizes, numArrays, &resultSize);

    printf("Merged array: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    // Free allocated memory
    free(merged);

    return 0;
}
