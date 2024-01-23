#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int temp, maximum, right_index, left_index;
    maximum = i;
    left_index = 2 * i + 1;
    right_index = 2 * i + 2;

    if (left_index < n && arr[left_index] > arr[maximum])
    {
        maximum = left_index;
    }

    if (right_index < n && arr[right_index] > arr[maximum])
    {
        maximum = right_index;
    }

    if (maximum != i)
    {
        temp = arr[i];
        arr[i] = arr[maximum];
        arr[maximum] = temp;
        heapify(arr, n, maximum);
    }
}

void heapSort(int arr[], int n)
{
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array is \n");
    printArray(arr, n);

    return 0;
}