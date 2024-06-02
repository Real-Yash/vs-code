#include <stdio.h>
int main(){

int a=2;
float b= 2.001;
char c='z';

printf("***welcome****\n");
printf("size of int a with value %d is %d \n" , a , sizeof a);
printf("size of float b with value %f is %d \n" , b, sizeof b);
printf("size of char c with value %c is %d \n" , c, sizeof c);

return 0;
}