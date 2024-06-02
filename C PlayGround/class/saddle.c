#include <stdio.h>

int main() 
{
    //declaring the variables
    int a[10][10], i, j, k, m, n, row_min, ci;

    //taking the inputs
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);

    //taking the elements
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; ++i) 
    {
        for (j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    }

    for (i = 0; i < m; i++) 
    { 
        //find the minimum element of row with its column index
        row_min = a[i][0], ci = 0; 
        for (j = 1; j < n; j++) 
        { 
            if (row_min > a[i][j]) 
            { 
                row_min = a[i][j]; 
                ci = j; 
            } 
        } 

        //checking the minimum element is the maximum element of the column or not
        for (k = 0; k < m; k++) 
        {
            // Note that col_ind is fixed 
            if (row_min < a[k][ci]) 
                break; 
        }

        // If saddle point is present 
        if (k == m) 
        { 
           printf("\nThe Saddle Point is: %d\n", row_min); 
           return 0;
        } 
    } 

    // If the Saddle Point not found 
    printf("\nThe saddle point is not present\n"); 
    return 0;
}
