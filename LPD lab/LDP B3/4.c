#include <stdio.h>

#define MAX_DEGREE 10

// Function to read a polynomial from user input
void readPolynomial(int *coefficients, int *degree) {
    printf("\nEnter the degree of the polynomial: ");
    scanf("%d", degree);
    printf("Enter the coefficients:\n");
    for (int i = *degree; i >= 0; i--) {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &coefficients[i]);
    }
}

// Function to display a polynomial
void displayPolynomial(int *coefficients, int degree) {
    for (int i = degree; i > 0; i--) {
        printf("%dx^%d + ", coefficients[i], i);
    }
    printf("%d\n", coefficients[0]);
}

// Function to add two polynomials
void addPolynomials(int *poly1, int degree1, int *poly2, int degree2, int *result, int *resultDegree) {
    *resultDegree = (degree1 > degree2) ? degree1 : degree2;
    for (int i = 0; i <= *resultDegree; i++) {
        result[i] = ((i <= degree1) ? poly1[i] : 0) + ((i <= degree2) ? poly2[i] : 0);
    }
}

// Function to multiply two polynomials
void multiplyPolynomials(int *poly1, int degree1, int *poly2, int degree2, int *result, int *resultDegree) {
    *resultDegree = degree1 + degree2;
    for (int i = 0; i <= *resultDegree; i++) {
        result[i] = 0;
        for (int j = 0; j <= i; j++) {
            if (j <= degree1 && (i - j) <= degree2) {
                result[i] += poly1[j] * poly2[i - j];
            }
        }
    }
}

// Function to evaluate a polynomial for a given value of x
int evaluatePolynomial(int *coefficients, int degree, int x) {
    int result = 0;
    for (int i = degree; i >= 0; i--) {
        result = result * x + coefficients[i];
    }
    return result;
}

int main() {
    int poly1[MAX_DEGREE + 1], degree1;
    int poly2[MAX_DEGREE + 1], degree2;
    int result[MAX_DEGREE * 2 + 1], resultDegree;

    // Enter details for the first polynomial
    printf("\nEnter details for the first polynomial:\n");
    readPolynomial(poly1, &degree1);

    // Enter details for the second polynomial
    printf("\nEnter details for the second polynomial:\n");
    readPolynomial(poly2, &degree2);

    // Display polynomials
    printf("\nFirst polynomial: ");
    displayPolynomial(poly1, degree1);
    printf("\nSecond polynomial: ");
    displayPolynomial(poly2, degree2);

    // Addition
    addPolynomials(poly1, degree1, poly2, degree2, result, &resultDegree);
    printf("\nAddition Result: ");
    displayPolynomial(result, resultDegree);

    // Multiplication
    multiplyPolynomials(poly1, degree1, poly2, degree2, result, &resultDegree);
    printf("\nmultiplication Result: ");
    displayPolynomial(result, resultDegree);

    // Evaluation
    int x;
    printf("\nEnter the value of x for evaluation: ");
    scanf("%d", &x);
    int evaluationResult = evaluatePolynomial(poly1, degree1, x);
    printf("Evaluation Result for the first polynomial: %d\n", evaluationResult);
    evaluationResult = evaluatePolynomial(poly2, degree2, x);
    printf("Evaluation Result for the second polynomial: %d\n", evaluationResult);

    return 0;
}
