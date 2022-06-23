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
    cout << "elements are"<< endl;
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
        cout<<endl;
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

int deleting (struct Array *arr, int index)
{
    int i,r;
     r=arr->A[index];//ie this index value is going to be deleted , and if anytime question will ask to return deleted value the we will return this.
    if(index>=0 && index<arr->length)
    {
    for(i=index;i<arr->length-1;i++)
    {
       arr->A[i]=arr->A[i+1];
    }
    arr->length--;
    }
    return r;
}
int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Append(&arr, 11);
    display(arr);

    Insert(&arr, 3, 10);
    display(arr);

    int r=deleting(&arr, 4);
    display(arr);
    cout<<"the deleted value is "<<r<<endl;
    return 0;
}