#include <stdio.h>
#include <conio.h>
#include <math.h>

#define MAX 10 // Maximum number of coefficients

// Function to evaluate the polynomial
float evaluatePolynomial(int coeffs[], int degree, float x)
{
     float result = 0;
     int i;
     for (i = 0; i <= degree; i++)
     {
          result += coeffs[i] * pow(x, i);
     }
     return result;
}

void main()
{
     int coeffs[MAX]; // Array to store coefficients
     int degree, i;
     float x, result;

     clrscr(); // Clear the screen

     // Read the degree of the polynomial
     printf("Enter the degree of the polynomial: ");
     scanf("%d", &degree);

     // Ensure degree is within bounds
     if (degree >= MAX)
     {
          printf("Degree exceeds the maximum allowed (%d).\n", MAX - 1);
          getch(); // Wait for a key press
          return;
     }

     // Read the coefficients of the polynomial
     printf("Enter the coefficients (from lowest degree to highest degree):\n");
     for (i = 0; i <= degree; i++)
     {
          printf("Coefficient of x^%d: ", i);
          scanf("%d", &coeffs[i]);
     }

     // Read the value of x
     printf("Enter the value of x: ");
     scanf("%f", &x);

     // Evaluate the polynomial
     result = evaluatePolynomial(coeffs, degree, x);

     // Display the result
     printf("The value of the polynomial at x = %.2f is: %.2f\n", x, result);

     getch(); // Wait for a key press
}
