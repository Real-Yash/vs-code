#include <stdio.h>
#include <math.h> 

    void main()
{
      unsigned long int x, z, s = 0, s1 = 0, e;
      int y, flag = 0, h;


      printf("How many digits relative address have?\n");
      scanf("%d", &y);
      printf("Enter the key value\n");
      scanf("%ld", &x);


      z = pow(10, y);
      while (x > 0)
      {
            e = x % z;
            x = x / z;
            if (flag == 0)
            {
                  while (e > 0)
                  {
                        h = e % 10;
                        e = e / 10;
                        s1 = s1 * 10 + h;
                  }
                  flag = 1;
                  e = s1;
            }
            s = s + e;
      }
      printf("\n the hashed value is : %ld ", s);
}