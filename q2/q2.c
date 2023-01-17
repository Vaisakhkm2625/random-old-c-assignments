//
//question2.c
#include <stdio.h>
#include <string.h>
#include "hi.h"


#define T 35 

struct productType{
  char item[40];
  int quantity;
  float price;
};

int main ()
{
  

  struct productType product[T];
  int noOfItems;

  char continueFlag='y';
  int i;

  float total=0;

  int discountPercent;
  float discount;
  float grandTotal;


// strcpy(product.item,"vai");


  printf("╔═══════════════════════════════════════════════╗\n");
  printf("║                    Welcome                    ║\n");
  printf("╠═══════════════════════════════════════════════╣\n");
  printf("║Instructions                                   ║\n");
  printf("╟────────────                                   ║\n");
  printf("║ - Use <tab> to move forward to next column,   ║\n");
  printf("║ - ONLY user <enter> key at the end            ║\n");
  printf("║ - To continue adding next item,enter 'y' 'Y'  ║\n");
  printf("║         and any other to stop                 ║\n");
  printf("╚═══════════════════════════════════════════════╝\n");

  printf("╔══════╤═══════════════╤═══════╤══════╤═════════╗\n");
  printf("║Sl No.│Item           │Quanti.│Price │continue?║\n");
  printf("╠══════╪═══════════════╪═══════╪══════╪═════════╣\n");

  for (i=0; i<T && (continueFlag == 'y' ||continueFlag == 'Y') ; i++) {
    printf("║      │               │       │      │         ║\r║%d\t",i+1);
    scanf("%s\t%d\t%f\t%c",product[i].item,&product[i].quantity,&product[i].price,&continueFlag);
  }
  printf("╚══════╧═══════════════╧═══════╧══════╧═════════╝\n");
  noOfItems = i;


  printf("╔══════════════════════════════════════════════════╗\n");
  printf("║                     Bill                         ║\n");
  printf("╠═══════╤═══════════════╤═══════╤═══════╤══════════╣\n");
  printf("║Sl No. │Item           │Quanti.│Price  │          ║\n");
  printf("╠═══════╪═══════════════╪═══════╪═══════╪══════════╣\n");

  for (i=0; i<noOfItems; i++) {
    float subtotal = product[i].quantity*product[i].price;
    printf("║%d\t│%-15s│%d\t│%.2f\t│%*.2f║\n",i+1,product[i].item,product[i].quantity,product[i].price,10,subtotal);
    total+=subtotal;
  }

  discountPercent = getDiscountPercentage(total);
  discount = -(total*discountPercent/100);
  grandTotal = (total+discount);

  printf("╠═══════╪═══════════════╪═══════╧═══════╪══════════╣\n");
  printf("║       │Total          │               │%*.2f║\n",10,total);
  printf("╟───────┼───────────────┼───────────────┼──────────╢\n");
  printf("║       │Discount       │%d%%\t\t│%*.2f║\n",discountPercent,10,discount);
  printf("╟───────┼───────────────┼───────────────┼──────────╢\n");
  printf("║       │Grand Total    │               │%*.2f║\n",10,grandTotal);
  printf("╚═══════╧═══════════════╧═══════════════╧══════════╝\n");



  return 0;
}
