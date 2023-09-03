#include <stdio.h>
int main(){
  char item[100];
  int quantity;
  float price, total_price, discount, grand_total;
  total_price = 0;
  char flag='y';
  printf("| Item | Quantity | Price | Sub-Total |\n");
  while (flag == 'y'){
    scanf("%s %d %f %c", item, &quantity, &price,&flag);
    float item_total = quantity * price;
    printf("| %-10s | %8d | %5.2f | %10.2f |\n", item, quantity, price, item_total);
    total_price += item_total;
  }


  if (total_price >= 10000){
    discount = 0.2 * total_price;
  }
  else if (total_price >= 5001){
    discount = 0.15 * total_price;
  }
  else if (total_price >= 2501){
    discount = 0.1 * total_price;
  }
  else if (total_price >= 1000){

    discount = 0.05 * total_price;
  }
  else{
    discount = 0;
  }
  grand_total = total_price - discount;
  printf("|------------|----------|-------|------------|\n");
  printf("|Total       |          |%10.2f |\n", total_price);
  printf("|            |Discount  |%10.2f |\n", discount);
  printf("|Grand total |          |%10.2f |\n", grand_total);
  printf("|------------|----------|-------|------------|\n");
}
