#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void BubbleSort(int A[], int n)
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
        if(flag==0)
        break; 
    }
}

int main()
{
    int A[] = {3, 7, 9, 10}, n = 4;
    BubbleSort(A,4);
    for (int i = 0; i <4; i++)
        cout << A[i] << " ";
    return 0;
}