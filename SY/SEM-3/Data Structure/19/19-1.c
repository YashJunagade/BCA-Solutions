#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Define maximum size for the stack and string

// Define a stack structure to hold words
typedef struct
{
     char *arr[MAX]; // Array to hold pointers to words
     int top;        // Index of the top element
} Stack;

// Function to create a stack
void createStack(Stack *stack)
{
     stack->top = -1; // Initialize the top of the stack to -1 (empty)
}

// Function to push a word onto the stack
void push(Stack *stack, char *word)
{
     if (stack->top < MAX - 1)
     {
          stack->arr[++stack->top] = word; // Increment top and add word to stack
     }
}

// Function to pop a word from the stack
char *pop(Stack *stack)
{
     if (stack->top >= 0)
     {
          return stack->arr[stack->top--]; // Return the top word and decrement top
     }
     return NULL; // Return NULL if stack is empty
}

// Function to reverse a word
void reverseWord(char *word)
{
     int start = 0;
     int end = strlen(word) - 1;
     while (start < end)
     {
          // Swap characters at start and end
          char temp = word[start];
          word[start] = word[end];
          word[end] = temp;
          start++;
          end--;
     }
}

// Function to reverse each word in a string
void reverseWords(char *str)
{
     Stack stack;
     createStack(&stack);

     char *token = strtok(str, " "); // Split the string into words by spaces

     while (token != NULL)
     {
          char *word = (char *)malloc(strlen(token) + 1); // Allocate memory for the word
          strcpy(word, token);                            // Copy the token into the new word
          reverseWord(word);                              // Reverse the word
          push(&stack, word);                             // Push the reversed word onto the stack
          token = strtok(NULL, " ");                      // Move to the next word
     }

     // Pop words from the stack and print them
     while (stack.top != -1)
     {
          printf("%s ", pop(&stack));
     }
     printf("\n");

     // Free allocated memory
     for (int i = 0; i <= stack.top; i++)
     {
          free(stack.arr[i]);
     }
}

int main()
{
     char str[MAX];

     // Get the input string from the user
     printf("Enter a string: ");
     fgets(str, sizeof(str), stdin);
     str[strcspn(str, "\n")] = '\0'; // Remove trailing newline

     // Reverse each word in the string
     printf("Reversed string with each word reversed: ");
     reverseWords(str);

     return 0;
}
