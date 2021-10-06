#include <stdio.h>
#include<stdlib.h>
void bubbleSort(int n, int arr[])
{
    int temp,sort = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sort = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sort = 0;
            }
        }
    }
    if (sort)
    {
        return;
    }
}

int binarySearch(int n, int arr[], int val)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    printf("Enter any one of the following options\n1.Bubble sort algorithm\n2.Linear search\n3.Displaying a sparse matrix\n4.Exit\n");
    while (1)
    {
        int choice, arr[20], n, val;
        printf("Enter the choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the length of the array (<19):\n");
            scanf("%d", &n);
            printf("Enter the elements of the array:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", arr[i]);
            }
            bubbleSort(n, arr);
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 2:
            printf("Enter the length of the array (<19):\n");
            scanf("%d", &n);
            printf("Enter the elements of the array:\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", arr[i]);
            }
            printf("Enter the element to be searched\n");
            scanf("%d", &val);
            if (binarySearch(n, arr, val))
            {
                printf("%d is present in the array:\n");
            }
            else
            {
                printf("%d is not present in your array\n", val);
            }
            break;
        default:
            printf("Bye Bye!!\n");
            return 0;
        }
    }
    return 0;
}