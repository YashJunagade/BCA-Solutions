#include <stdio.h>
#include <conio.h>

#define MAX_TERMS 10 // Define maximum number of terms in a polynomial

// Function to read a polynomial
void readPolynomial(int poly[], int *degree)
{
     int i;
     printf("Enter the degree of the polynomial: ");
     scanf("%d", degree);

     printf("Enter the coefficients from highest degree to lowest:\n");
     for (i = *degree; i >= 0; i--)
     {
          printf("Coefficient of x^%d: ", i);
          scanf("%d", &poly[i]);
     }
}

// Function to print a polynomial
void printPolynomial(int poly[], int degree)
{
     int i;
     printf("Polynomial: ");
     for (i = degree; i >= 0; i--)
     {
          if (i != degree && poly[i] >= 0)
               printf(" + ");
          if (i == 0)
               printf("%d", poly[i]);
          else
               printf("%dx^%d", poly[i], i);
     }
     printf("\n");
}

// Function to add two polynomials
void addPolynomials(int poly1[], int degree1, int poly2[], int degree2, int result[], int *resultDegree)
{
     int i, maxDegree;

     // Determine the maximum degree of the result polynomial
     if (degree1 > degree2)
          maxDegree = degree1;
     else
          maxDegree = degree2;

     // Initialize result polynomial to 0
     for (i = 0; i <= maxDegree; i++)
          result[i] = 0;

     // Add coefficients of the first polynomial
     for (i = 0; i <= degree1; i++)
          result[i] += poly1[i];

     // Add coefficients of the second polynomial
     for (i = 0; i <= degree2; i++)
          result[i] += poly2[i];

     // Set the degree of the result polynomial
     *resultDegree = maxDegree;
}

void main()
{
     int poly1[MAX_TERMS], poly2[MAX_TERMS], result[MAX_TERMS];
     int degree1, degree2, resultDegree;

     clrscr(); // Clear the screen

     // Read the first polynomial
     printf("Enter the first polynomial:\n");
     readPolynomial(poly1, &degree1);

     // Read the second polynomial
     printf("Enter the second polynomial:\n");
     readPolynomial(poly2, &degree2);

     // Add the two polynomials
     addPolynomials(poly1, degree1, poly2, degree2, result, &resultDegree);

     // Print the polynomials and the result
     printf("First ");
     printPolynomial(poly1, degree1);

     printf("Second ");
     printPolynomial(poly2, degree2);

     printf("Sum ");
     printPolynomial(result, resultDegree);

     getch(); // Wait for a key press
}
