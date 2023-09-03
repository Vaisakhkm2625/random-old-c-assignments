#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// Binary Tree node
struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

int calculateHeight(struct TreeNode *root) {
  if (root == NULL)
    return 0;
  return (calculateHeight(root->left) > calculateHeight(root->right)
              ? calculateHeight(root->left)
              : calculateHeight(root->right)) +
         1;
}

int getcol(int h) {
  if (h == 1)
    return 1;
  return getcol(h - 1) + getcol(h - 1) + 1;
}

void printTree(int **M, struct TreeNode *root, int col, int row, int height) {
  if (root == NULL)
    return;
  M[row][col] = root->data;
  printTree(M, root->left, col - pow(2, height - 2), row + 1, height - 1);
  printTree(M, root->right, col + pow(2, height - 2), row + 1, height - 1);
}

void treePrinter(struct TreeNode *root) {
  int h = calculateHeight(root);
  int col = getcol(h);
  int **M = malloc(sizeof(int) * h);

  for (int i = 0; i < h; i++) {
    M[i] = malloc(sizeof(int[col]));
  }
  printTree(M, root, col / 2, 0, h);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < col; j++) {
      if (M[i][j] == 0)
        printf("  ");
      else
        printf("%d ", M[i][j]);
    }
    printf("\n");
  }
}

struct TreeNode *newNode(int data);
// convert BBT from sorted array
struct TreeNode *sortedArrayToBST(int arr[], int start, int end) {
  if (start > end)
    return NULL;
  // Get the middle element and make it root
  int mid = (start + end) / 2;

  struct TreeNode *root = newNode(arr[mid]);

  // Recursively construct the left subtree and make it left child of root
  root->left = sortedArrayToBST(arr, start, mid - 1);

  // Recursively construct the right subtree and make it right child of root
  root->right = sortedArrayToBST(arr, mid + 1, end);
  return root;
}

// create new node
struct TreeNode *newNode(int data) {
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// print preorder traversal of BST
void preOrder(struct TreeNode *node) {
  if (node == NULL)
    return;
  printf("%d ", node->data);
  preOrder(node->left);
  preOrder(node->right);
}

int main() {
  int sortedArray[50], n;

  printf("Enter the size of array\n ");
  scanf("%d", &n);

  printf("Enter sorted array\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &sortedArray[i]);

  // convert to BST
  struct TreeNode *root = sortedArrayToBST(sortedArray, 0, n - 1);
  printf("PreOrder Traversal of constructed BST\n");
  preOrder(root);

  printf("\n\n");
  treePrinter(root);
  printf("\n\n");
  printf("The root of the tree is %d \n", root->data);
  return 0;
}
