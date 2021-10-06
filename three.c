#include <stdio.h>
#include <stdlib.h>
#define max 10

struct stack
{
    int size;
    int top;
    int *arr;
};
struct stack *createStack()
{
    struct stack *s = malloc(sizeof(struct stack));
    if (!s)
    {
        return NULL;
    }
    s->top = -1;
    s->size = max;
    s->arr = (int *)malloc(max * sizeof(int));
    if (!s->arr)
    {
        return NULL;
    }
    return s;
}
int isEmpty(struct stack *s)
{
    return (s->top == -1);
}
int isFull(struct stack *s)
{
    return (s->top == s->size - 1);
}
void push(struct stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = data;
}
int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return 0;
    }
    int data = s->arr[s->top];
    s->top--;
    return data;
}
int palindrome(int n, int arr[])
{
    struct stack *s = createStack();
    if (n % 2 != 0)
    {
        int r = (n + 1) / 2;
        for (int i = 0; i < r; i++)
        {
            push(s, arr[i]);
        }
        int m = pop(s);
        for (int i = r; i < n; i++)
        {
            if (arr[i] != pop(s))
            {
                return 0;
            }
        }
        return 1;
    }
    else if (n % 2 == 0)
    {
        int r = (n) / 2;
        for (int i = 0; i < r; i++)
        {
            push(s, arr[i]);
        }
        for (int i = r; i < n; i++)
        {
            if (arr[i] != pop(s))
            {
                return 0;
            }
        }
        return 1;
    }
}

int length(struct stack *s)
{
    return s->top + 1;
}

void status(struct stack *s)
{
    if (length(s) == 0)
    {
        printf("Stack is empty!!\n");
    }
    else if (length(s) == s->size)
    {
        printf("Stack if full!!\n");
    }
    else
    {
        printf("The current length of the stack is %d\n", length(s));
    }
}

void printStack(struct stack *s)
{
    if (isEmpty(s))
    {
        return;
    }
    for (int i = 0; i < length(s); i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct stack *s = createStack();
    printf("Choose any one of the following options:\n1.Push an element on to the stack\n2.Pop an element from the stack\n3.Check for Palindromes\n4.Display the status of the stack\n5.Print the stack(from bottom to top)\n6.Exit\n");
    while (1)
    {
        int choice, pu, po, narr[10], len, length;
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed:\n");
            scanf("%d", &pu);
            push(s, pu);
            printf("%d is pushed\n", pu);
            break;
        case 2:
            printf("%d is poped\n", pop(s));
            break;
        case 3:
            printf("Enter the length of the palindrome (<10):\n");
            scanf("%d", &len);
            printf("Enter the palindrome of length %d:\n", len);
            for (int i = 0; i < len; i++)
            {
                scanf("%d", &narr[i]);
            }
            if (palindrome(len, narr))
            {
                printf("The given array is Palindromic\n");
            }
            else
            {
                printf("The given array is not Palindromic\n");
            }
            break;
        case 4:
            printf("The stack status is:\n");
            status(s);
            break;
        case 5:
            printf("The elements of the stack are:\n");
            printStack(s);
            break;
        case 6:
            printf("Bye bye!!\n");
            return 0;
        }
    }
    return 0;
}