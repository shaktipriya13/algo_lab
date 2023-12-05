#include <stdio.h>
#include <stdlib.h>

void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void SelectionSort(int A[], int n)
{
    int i, j, k;

    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}
int main()
{
    int A[100];
    int n;
    printf("Enter the size of the array :\n");
    scanf("%d", &n);

    printf("Input Elements :\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("The printed array is: ");
    display(A, n);
    SelectionSort(A, n);
    // for (int i = 0; i < n; i++)
    //     printf("%d ", A[n]);
    // // printf("\n");
    printf("The sorted array is: ");
    display(A, n);
    // int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    // SelectionSort(A, n);

    // for (i = 0; i < 10; i++)
    //     printf("%d ", A[i]);
    // printf("\n");

    return 0;
}
