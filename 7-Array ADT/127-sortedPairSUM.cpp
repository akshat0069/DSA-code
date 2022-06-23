#include <iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};

void findSUM(struct Array arr)
{
    int n = arr.length;
    int i = 0, j = n - 1;
    int k = 9;
    while (i < j)
    {

        if (arr.A[i] + arr.A[j] == k)
        {
            cout << "the result is " << arr.A[i] <<" + "<< arr.A[j] << "=" << k << endl;
            i++;
            j--;
        }

        else if (arr.A[i] + arr.A[j] < k)
        {
            i++;
        }

        if (arr.A[i] + arr.A[j] > k)
        {
            j--;
        }
    }
}
int main()
{
    struct Array arr = {{1, 3, 4, 5, 6, 8, 9, 10, 12, 14}, 20, 10};
    findSUM(arr);
    return 0;
}