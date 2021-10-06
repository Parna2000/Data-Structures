#include <stdio.h>
#include <stdlib.h>
#define max 10

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
struct queue *createQueue()
{
    struct queue *q = malloc(sizeof(struct queue));
    if (!q)
    {
        return NULL;
    }
    q->size = max;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(max * sizeof(int));
    if (!q->arr)
    {
        return NULL;
    }
    return q;
}

int isEmpty(struct queue *q)
{
    return (q->f == -1);
}
int isFull(struct queue *q)
{
    return ((q->r + 1) % q->size == q->f);
}
void EnQueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue overflow!!\n");
        return;
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = data;
        if (q->f == -1)
        {
            q->f = q->r;
        }
    }
}
int DeQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow!!\n");
        return 0;
    }
    else
    {
        int data = q->arr[q->f];
        if (q->f == q->r)
        {
            q->f = q->r = -1;
        }
        else
        {
            q->f = (q->f + 1) % q->size;
        }
        return data;
    }
}
int length(struct queue *q)
{
    if(q->f==-1)
    return 0;
    else
    return ((q->size - q->f + q->r + 1) % q->size);
}
void status(struct queue *q)
{
    if (length(q) == 0)
    {
        printf("Queue is empty!!\n");
    }
    else if (length(q) == q->size)
    {
        printf("Queue is full!!\n");
    }
    else
    {
        printf("The current length of the queue is: %d\n", length(q));
    }
}
void printQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        printf("The queue is:\n");
        for (int i = q->f; i <=q->r; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    struct queue *q = createQueue();
    printf("Choose any one of the following options:\n1.Enqueue an element on to the queue\n2.Dequeue an element from the queue\n3.Display the status of the queue\n4.Print the queue\n5.Exit\n");
    while (1)
    {
        int choice, pu, po;
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be enqueued:\n");
            scanf("%d", &pu);
            EnQueue(q, pu);
            printf("%d is enqueued\n", pu);
            break;
        case 2:
            printf("%d is dequeued\n", DeQueue(q));
            break;
        case 3:
            printf("The queue status is:\n");
            status(q);
            break;
        case 4:
            printQueue(q);
            break;
        case 5:
            printf("Bye bye!!\n");
            return 0;
        }
    }
    return 0;
}