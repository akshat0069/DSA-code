#include <iostream>

using namespace std;
struct Array
{
    int A[10];
    int size;
    int length; //no of elements in array
};
void display(struct Array arr)
{
    int i;
    cout << "elements are" << endl;
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 || index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}
int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    // Append(&arr, 11);
    Insert(&arr, 3, 10);
    display(arr);
    return 0;
}