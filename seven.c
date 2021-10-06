#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *createNode(int data)
{
    struct node *head = malloc(sizeof(struct node));
    if (!head)
    {
        return NULL;
    }
    head->data = data;
    head->next = NULL;
    return head;
}
int length(struct node *head)
{
    int l = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        l++;
    }
    return l;
}
void printList(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
struct node *InsertAtBeginning(struct node *head, int data)
{
    struct node *p = head;
    struct node *q = createNode(data);
    q->next = p;
    p = q;
    return q;
}
struct node *DeleteAtBeginning(struct node *head)
{
    struct node *p = head;
    struct node *q = head;
    p = p->next;
    free(q);
    return p;
}
struct node *InsertAtEnd(struct node *head, int data)
{
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    struct node *q = createNode(data);
    q->next = NULL;
    p->next = q;
    return head;
}
struct node *DeleteAtEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
// for stack
int main()
{
    struct node *head = createNode(26);
    struct node *stack = createNode(33);
    struct node *queue = createNode(45);
    printf("Choose any one of the following options:\n1.Print the linked list\n2.Length of the linked list\n3.Insert at the end of the linked list\n4.Delete at the end of the linked list\n5.Insert at the beginning of the linked list\n6.Delete at the beginning of the linked list\n7.Push into the stack\n8.Pop out of the stack\n9.Print the stack\n10.Enqueue into the queue\n11.Dequeue from the queue\n12.Print the queue\n13.Exit!!\n");
    while (1)
    {
        int choice, data;
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The list is:\n");
            printList(head);
            break;
        case 2:
            printf("The length of the linked list is: %d\n", length(head));
            break;
        case 3:
            printf("Enter the element to be inserted:\n");
            scanf("%d", &data);
            head = InsertAtEnd(head, data);
            printf("%d is inserted at the end\n", data);
            break;
        case 4:
            head = DeleteAtEnd(head);
            printf("Deletion is made at the end\n");
            break;
        case 5:
            printf("Enter the element to be inserted:\n");
            scanf("%d", &data);
            head = InsertAtBeginning(head, data);
            printf("%d is inserted at the beginning\n", data);
            break;
        case 6:
            head = DeleteAtBeginning(head);
            printf("Deletion is made at the beginning\n");
            break;
        case 7:
            printf("Enter the element to be pushed:\n");
            scanf("%d", &data);
            stack = InsertAtEnd(stack, data);
            printf("%d is pushed into the stack\n", data);
            break;
        case 8:
            stack = DeleteAtEnd(stack);
            printf("Poping is done\n");
            break;
        case 9:
            printf("The stack is:\n");
            printList(stack);
            break;
        case 10:
            printf("Enter the element to be enqueued:\n");
            scanf("%d", &data);
            queue = InsertAtEnd(queue, data);
            printf("%d is enqueued\n", data);
            break;
        case 11:
            queue = DeleteAtBeginning(queue);
            printf("Dequeuing is done\n");
            break;
        case 12:
            printf("The queue is:\n");
            printList(queue);
            break;
        case 13:
            printf("Bye bye!!\n");
            return 0;
        }
    }
    return 0;
}