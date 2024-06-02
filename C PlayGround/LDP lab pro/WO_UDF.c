#include <stdio.h>

int main() {

  int OTP[] = {4,2,0,6,9,7,5,1,3,8,7,4,5,1,2,3,4,5,8,9};
  printf("\nThe 20 digit OTP for WATER METER fixing @public office is: *");

  //to print original OTP
  for (int i=0;i<20;i++) 
    printf("%d",OTP[i]);   
  printf("* \n\n");
  
  int n = 20;

  //sorting OTP in ascending order
  for (int i = 0; i < n-1; i++) {
   int max_idx = i;
    for (int j = i+1; j < n; j++){

      if (OTP[j] > OTP[max_idx]){
        max_idx = j;
      }

      //for swap
      if (max_idx != i) {
        int temp = OTP[max_idx];
        OTP[max_idx] = OTP[i];
        OTP[i] = temp;
      }
    } 
  } 
  printf("Sorted OTP in descending order is:\n ");

  //for printing sorted OTP
  for (int i = 0; i < n; i++)
    printf("%d ", OTP[i]);
  printf("\n\n");
     
return 0;
}


