#include <stdio.h>

int main(int argc, char *argv[]) {

  int intenvels_count, internvels[10][2];
  for (int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }

  printf("how many internvels?");
  scanf("%d", &intenvels_count);

  for (int i = 0; i < intenvels_count; i++) {
    scanf("%d,%d\n", &internvels[i][0], &internvels[i][1]);
  }

  for (int i = 0; i < intenvels_count; i++) {
    printf("%d,%d\n", internvels[i][0], internvels[i][1]);
  }
  return 0;
}
