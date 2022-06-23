#include <iostream>
using namespace std;
struct Array
{
    int *A;
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

int main()
{
    int ch;
    struct Array arr1;
    cout << "enter the size of array" << endl;
    cin >> arr1.size;
    arr1.A = new int[sizeof(struct Array)];

    cout << "Menu";
    cout << "insert";
    cout << "Delete";
    cout << "search";
    cout << "Sum";
    cout << "display";
    cout << 'Exit';

    cout << "Enter your choice ";

    return 0;
}