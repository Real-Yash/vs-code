#include<stdio.h>

#define MAX 20

typedef struct {
    int row;
    int col;
    int val;
} sparse;

sparse s[MAX];

void readsparse(sparse *s, int m, int n) {
    int i, j, k = 1, item;
    s[0].row = m;
    s[0].col = n;
    printf("Enter elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &item);
            if (item == 0)
                continue;
            s[k].row = i;
            s[k].col = j;
            s[k].val = item;
            k++;
        }
    }
    s[0].val = k - 1;
}

void displaysparse(sparse *s) {
    int i;
    // printf("The non-zero elements of the matrix are:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 1; i <= s[0].val; i++)
        printf("%d\t%d\t%d\n", s[i].row, s[i].col, s[i].val);
}

void addsparse(sparse *s1, sparse *s2, sparse *s3) {
    int i = 1, j = 1, k = 1;
    while (i <= s1[0].val && j <= s2[0].val) {
        if (s1[i].row < s2[j].row) {
            s3[k] = s1[i];
            k++;
            i++;
        } else if (s1[i].row > s2[j].row) {
            s3[k] = s2[j];
            k++;
            j++;
        } else if (s1[i].col < s2[j].col) {
            s3[k] = s1[i];
            k++;
            i++;
        } else if (s1[i].col > s2[j].col) {
            s3[k] = s2[j];
            k++;
            j++;
        } else {
            s3[k].row = s1[i].row;
            s3[k].col = s1[i].col;
            s3[k].val = s1[i].val + s2[j].val;
            k++;
            i++;
            j++;
        }
    }
    while (i <= s1[0].val) {
        s3[k] = s1[i];
        k++;
        i++;
    }
    while (j <= s2[0].val) {
        s3[k] = s2[j];
        k++;
        j++;
    }
    s3[0].row = s1[0].row;
    s3[0].col = s1[0].col;
    s3[0].val = k - 1;
}

int main() {
    sparse s1[MAX], s2[MAX], s3[MAX];
    int m, n;
    printf("Enter the size of the matrix:\n");
    scanf("%d%d", &m, &n);
    printf("Enter the elements of the first matrix:\n");
    readsparse(s1, m, n);
    printf("The non-zero elements of the first matrix are:\n");
    displaysparse(s1);
    printf("Enter the elements of the second matrix:\n");
    readsparse(s2, m, n);
    printf("The non-zero elements of the second matrix are:\n");
    displaysparse(s2);
    addsparse(s1, s2, s3);
    printf("The resultant sparse matrix is:\n");
    displaysparse(s3);
    return 0;
}
