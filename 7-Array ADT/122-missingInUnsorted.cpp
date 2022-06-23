#include <iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};
int main()
{
    struct Array arr = {{3, 7, 4, 9, 12, 6, 1, 11, 2, 10}, 20, 10};
    int *H;
    int i, l, h, n;
    l = 1;
    h = 12;
    n = 10;
    //making array
    H = new int[h];

    //Initializing array with -1
    for (i = 0; i < h; i++)
    {
        H[i] = -1;
    }

//increasing array H with 1 ie -1 + 1 =0;
    for (i = 0; i < h; i++)
    {
        H[arr.A[i]]++;
    }

//checking for the places with value -1 , that means those are missing
    for (i = l; i <= h; i++)
    {

        if (H[i] == -1)
        {
            cout << "missing element is " << i << endl;
        }
    }
    return 0;
}