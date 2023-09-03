#include <stdio.h>
#include "algorithm.h"

#define MAX 10

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main (int argc, char *argv[])
{

  int arr[MAX];
  int val;

  printf("Enter array of %d integer\n",MAX);

  for (int i = 0; i < MAX; i++) {
    scanf("%d",&arr[i]);
  }

  printf("Enter value you want to search ");

  scanf("%d",&val);

  int pos = searchInArrayOfElements(val, arr,MAX );


  if (pos == -1) {
    printf("There is no such value in the given array \n");
    return 0;
  }

  printf("Position of value in array is %d\n",pos);

  sortArrayOfElements(arr, MAX);

  printf("\nsorted array is\n");
  printArray(arr, MAX);

  return 0;
}
