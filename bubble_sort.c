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
void Bubble(int A[], int n)
{
    int i, j, flag = 0;

    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}
int main()
{
    // int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
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
    Bubble(A, n);
    // for (int i = 0; i < n; i++)
    //     printf("%d ", A[n]);
    // // printf("\n");
    printf("The sorted array is: ");
    display(A, n);

    return 0;
}

