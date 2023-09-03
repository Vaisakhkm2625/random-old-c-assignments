int getDiscountPercentage(float amount){

    if(1000<=amount && amount<=2500){
      return 5;
    }
    else if (2501<=amount && amount<=5000){
      return 10;
    }
    else if (5001<=amount && amount<=10000){
      return 15;
    }
    else if (amount>=10000){
      return 20;
   }
  return 0;
}


