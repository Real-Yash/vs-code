#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PEOPLE 50 // number of people in the group
#define NUM_DAYS 365 // number of days in a year

int main() {
  int birthdays[NUM_PEOPLE]; // array to store the birthdays
  int i, j; // loop variables
  int match = 0; // flag to indicate if there is a match

  srand(time(NULL)); // seed the random number generator

  // generate and print 50 random numbers between 1 and 365
  printf("The birthdays of %d people are:\n", NUM_PEOPLE);
  for (i = 0; i < NUM_PEOPLE; i++) {
    birthdays[i] = rand() % NUM_DAYS + 1; // random number between 1 and 365
    printf("%d ", birthdays[i]);
  }
  printf("\n");

  // compare each pair of numbers to see if there is a match
  for (i = 0; i < NUM_PEOPLE - 1; i++) {
    for (j = i + 1; j < NUM_PEOPLE; j++) {
      if (birthdays[i] == birthdays[j]) {
        match = 1; // set the flag to true

        printf("")
        break; // exit the inner loop
      }
    }
    if (match) {
      break; // exit the outer loop
    }
  }



  // print the result based on the flag
  if (match) {
    printf("There is a match!\n");
  } else {
    printf("There is no match!\n");
  }

  return 0;
}
