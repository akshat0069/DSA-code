#include <iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};

void findDuplicate(struct Array arr)
{
    int lastDuplicate = 0;
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] == arr.A[i + 1] && arr.A[i] != lastDuplicate)
        {
            cout << "the duplicate is " << arr.A[i] << endl;
            lastDuplicate = arr.A[i];
        }
    }
}

void countDuplicate(struct Array arr)
{
    int i, j;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] == arr.A[i + 1])
        {
            j = i + 1;
            while (arr.A[j] == arr.A[i])
            {
                j++;
            }
            cout << "duplicate of " << arr.A[i] << " is " << j - i << "times" << endl;
            i = j - 1;
        }
    }
}
int main()
{
    struct Array arr = {{3, 6, 8, 8, 10, 12, 15, 15, 15, 20}, 20, 10};
    findDuplicate(arr);
    countDuplicate(arr);
    return 0;
}