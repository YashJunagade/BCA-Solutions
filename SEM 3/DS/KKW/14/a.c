/*A) Write a ‘C’ program to accept a string from user and reverse it using Dynamic
implementation of Stack.
*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Stack
// {
//     char data;
//     struct Stack *next;
// };

// struct Stack *top;

// void push(char data)
// {
//     struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
//     newNode->data = data;

//     newNode->next = top;
//     top = newNode;
// }

// char pop()
// {
//     if (top == NULL)
//         printf("Stack is empty");
//     char data = top->data;
//     top = top->next;
//     return data;
// }

// void reverseStr(char *str)
// {
//     int i;

//     int len = strlen(str);
//     for (i = 0; i < len; i++)
//         push(str[i]);

//     for (i = 0; i < len; i++)
//         str[i] = pop();
// }

// int main()
// {
//     char str[100];
//     printf("Enter string :");
//     gets(str);

//     reverseStr(str);
//     printf("Reverse string : %s", str);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Node
// {
//     char data;
//     struct Node *next;
// };

// struct Node *top, *temp, *newNode;

// void push(char c)
// {
//     newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = c;

//     newNode->next = top;
//     top = newNode;
// }
// char pop()
// {
//     if (top == NULL)
//         printf("Stack is empty");
//     char c = top->data;
//     top = top->next;
//     return c;
// }

// void reverseStr(char str[])
// {
//     int i, len = strlen(str);
//     for (i = 0; i < len; i++)
//         push(str[i]);
//     for (i = 0; i < len; i++)
//         str[i] = pop();
// }

// int main()
// {
//     char str[100];
//     printf("Enter string :");
//     gets(str);

//     reverseStr(str);
//     printf("Reverse String : %s", str);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Stack
// {
//     char data;
//     struct Stack *next;
// };

// struct Stack *top, *newNode, *temp;

// void push(char c)
// {
//     newNode = (struct Stack *)malloc(sizeof(struct Stack));
//     newNode->data = c;
//     newNode->next = top;
//     top = newNode;
// }

// char pop()
// {
//     char c = top->data;
//     top = top->next;
//     return c;
// }

// void reverseStr(char str[])
// {
//     int i, len = strlen(str);
//     for (i = 0; i < len; i++)
//         push(str[i]);
//     for (i = 0; i < len; i++)
//         str[i] = pop();
// }

// int main()
// {
//     char str[100];
//     printf("Enter string :");
//     gets(str);

//     reverseStr(str);
//     printf("Reverse String : %s", str);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *top, *newNode;

void push(char data)
{
    newNode = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->data = data;
    newNode->next = NULL;
    if (top == NULL)
        top = newNode;
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

char pop()
{
    char temp;
    if (top == NULL)
        printf("Stack is empty");
    else
    {
        temp = top->data;
        top = top->next;
    }
    return temp;
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

void reverseStr(char str[])
{
    int i, len = strlen(str);
    for (i = 0; i < len; i++)
        push(str[i]);
    for (i = 0; i < len; i++)
        printf("%c", pop());
}

int main()
{
    char str[20];
    printf("Enter the string :");
    gets(str);

    printf("Reverse String :");
    reverseStr(str);
    return 0;
}