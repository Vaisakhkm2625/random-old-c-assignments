#include <stdio.h>
#include <string.h>

int main(void) {

  // Declare variables
  //int quantity;
  float quantity, price, total_price = 0, discount, grand_total;
  char item[100];
  char choice;
  int num_items = 0;
  float quantities[100], prices[100], item_total_prices[100], item_discounts[100];
  char items[50][50] ={};

  do {
    // Get item, quantity and price from user
    printf("Item %d: ", num_items+1);
    scanf("%s",items[num_items]);
    //printf("%s", item);
    printf("Enter quantity: ");
    scanf("%f", &quantities[num_items]);
    printf("Enter price: ");
    scanf("%f", &prices[num_items]);

    // Calculate total price for this item
    item_total_prices[num_items]= quantities[num_items]*prices[num_items] ;
    // Calculate discount for this item

    num_items++;
    // discount += item_discount;

    printf("Do you want to enter more items? (Y/N) ");
    scanf(" %c", &choice);

  } while (choice == 'Y' || choice == 'y');

  // Print table header
  printf("\n\nItem\tQuantity\tPrice\tTotal Price\n");

  // Print details for each item
  for (int i = 0; i < num_items; i++) {
    printf("%s\t%.0f\t\t%.2f\t\t%.2f\n", items[i], quantities[i], prices[i], item_total_prices[i]);
    total_price += item_total_prices[i] ;
  }

  float item_discount;
  if (total_price>= 10000) {
    item_discount =total_price * 0.20;
  } else if (total_price >= 5001) {
    item_discount = total_price * 0.15;
  } else if (total_price >= 2501) {
    item_discount = total_price * 0.10;
  } else if (total_price >= 1000) {
    item_discount = total_price * 0.05;
  } else {
    item_discount = 0;
  }

  // Calculate grand total
  grand_total = total_price - item_discount;

  // Print final results
  printf("\nSub total: %.2f\n", total_price);
  printf("Discount: -%.2f\n", item_discount);
  printf("Grand total: %.2f\n", grand_total);
  return 0;
}

