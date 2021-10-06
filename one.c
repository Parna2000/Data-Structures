#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[20];
    printf("Choose any one of the following options:\n1.Creating an array of n elements\n2.Display the array elements with suitable headings\n3.Inserting an element at a given valid position\n4.Deleting an element at a given valid position\n5.Exit\n");
    while (1)
    {
        int choice, pos, n, val;
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value of n (< 19):\n");
            scanf("%d", &n);
            printf("Enter the elements of the array\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("An array of length %d is created\n", n);
            break;
        case 2:
            printf("The array is:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 3:
            printf("Enter the position at which you want insertion:\n");
            scanf("%d", &pos);
            printf("Enter the value to be inserted:\n");
            scanf("%d", &val);
            for (int i = n ; i > pos - 1; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = val;
            n = n + 1;
            printf("%d is inserted\n",val);
            break;
        case 4:
            printf("Enter the position at which you want deletion\n");
            scanf("%d", &pos);
            for (int i = pos - 1; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n = n - 1;
            break;
        case 5:
            printf("Bye bye!!\n");
            return 0;
        }
    }
    return 0;
}