// Tree traversal in non-recursive way
#include <stdio.h>
#include <stdlib.h>
#define max 20
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct stack
{
    int size;
    int top;
    struct node **arr;
};

struct stack *createStack()
{
    struct stack *s = malloc(sizeof(struct stack));
    if (!s)
    {
        return NULL;
    }
    s->size = max;
    s->top = -1;
    s->arr = malloc(max * sizeof(struct node *));
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

void push(struct stack *s, struct node *root)
{
    if (isFull(s))
    {
        printf("Stack overflow!!\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = root;
    }
}

struct node *pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!!\n");
    }
    struct node *root = s->arr[s->top];
    s->top--;
    return root;
}

struct node *top(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!!\n");
    }
    struct node *root = s->arr[s->top];
    return root;
}

struct node *createNode(int data)
{
    struct node *root = malloc(sizeof(struct node));
    if (!root)
    {
        return NULL;
    }
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void preOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct stack *s = createStack();
    while (1)
    {
        while (root)
        {
            printf("%d ", root->data);
            push(s, root);
            root = root->left;
        }
        if (isEmpty(s))
        {
            break;
        }
        root = pop(s);
        root = root->right;
    }
    printf("\n");
}

void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct stack *s = createStack();
    while (1)
    {
        while (root)
        {
            push(s, root);
            root = root->left;
        }
        if (isEmpty(s))
        {
            break;
        }
        root = pop(s);
        printf("%d ", root->data);
        root = root->right;
    }
    printf("\n");
}

void postOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct stack *s = createStack();
    struct node *previous = NULL;
    do
    {
        while (root)
        {
            push(s, root);
            root = root->left;
        }
        while (root == NULL && isEmpty(s) != 1)
        {
            root = top(s);
            if (root->right == NULL || root->right == previous)
            {
                printf("%d ", root->data);
                root = pop(s);
                previous = root;
                root = NULL;
            }
            else
            {
                root = root->right;
            }
        }
    } while (!isEmpty(s));
    printf("\n");
}

int main()
{
    struct node *root = createNode(23); /*           23          */
    struct node *r1 = createNode(20);   /*           /\          */
    struct node *r2 = createNode(25);   /*          20 25        */
    struct node *r3 = createNode(18);   /*          /\  /\       */
    struct node *r4 = createNode(21);   /*         18 21 24 26   */
    struct node *r5 = createNode(24);
    struct node *r6 = createNode(26);
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;
    printf("Choose any one of the following:\n1.Preorder Traversal\n2.Inorder Traversal\n3.Postorder Traversal\n4.Exit\n");
    while (1)
    {
        int choice;
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The preorder traversal of the above tree is:\n");
            preOrder(root);
            printf("\n");
            break;
        case 2:
            printf("The inorder traversal of the above tree is:\n");
            inOrder(root);
            printf("\n");
            break;
        case 3:
            printf("The postorder traversal of the above tree is:\n");
            postOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Bye Bye!!\n");
            return 0;
        }
    }
    return 0;
}