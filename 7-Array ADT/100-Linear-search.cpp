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
    cout << endl;
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
    if (index >= 0 || index <= arr->length)
    {
        int i;
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int deleting(struct Array *arr, int index)
{
    int i, r;
    r = arr->A[index]; //ie this index value is going to be deleted , and if anytime question will ask to return deleted value the we will return this.
    if (index >= 0 && index < arr->length)
    {
        for (i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
    return r;
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            // swap(&arr->A[i],&arr->A[i-1]);//this method is called TRANSPOSITION
            swap(&arr->A[i], &arr->A[0]); //this method is called MOVE TO FRONT/HEAD
            return i;
        }
    }
    return -1;
}
int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    cout << LinearSearch(&arr, 5) << " ";
    display(arr);
    return 0;
}