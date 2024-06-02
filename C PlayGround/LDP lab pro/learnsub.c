//Arrange and sort the 20 numeric OTPs "42069751387451234589" of water meter fixed at public office using Selection Sort algorithm in C programming.

#include <stdio.h>

int main() 
{
 int OTP[] = {4,2,0,6,9,7,5,1,3,8,7,4,5,1,2,3,4,9,5,8};
 printf( "\nThe 20 digit OTP for WATER METER fixing @public office is *");

      for (int i=0;i<20;i++)    
         printf("%d",OTP[i]);   
      printf("* \n \n");
         
    int n = 20;
    
    // loop throug (i+1)unsorted arry
    for (int i = 0; i < n-1; i++) 
      {
        // to find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (OTP[j] < OTP[min_idx])
                min_idx = j;
        
       // Swap the found minimum element with the i+1th element
        if (min_idx != i) 
            {
             int temp = OTP[min_idx];
             OTP[min_idx] = OTP[i];
             OTP[i] = temp;
            }
      }
    
    // Print the sorted array
    printf("idk why but sorted OTP in accending order with \n Selection sorting is:\n");
    for (int i = 0; i < n; i++)
        printf("%d %d \n", i , OTP[i]);
    printf("\n\n");
    
    return 0;
}
