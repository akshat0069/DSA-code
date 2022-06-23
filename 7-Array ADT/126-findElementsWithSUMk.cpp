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
    int i, j,k;
    k=18;
    int n = arr.length;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
          if(arr.A[i]+arr.A[j]==k)
          {
              cout<<"the result is "<<arr.A[i]<<" + "<<arr.A[j]<<" = "<<k<<endl;
          }
        }
    }
}
int main()
{
    struct Array arr = {{6, 3, 8, 10, 16, 7, 5, 2, 9, 14}, 20, 10};
    findSUM(arr);
    return 0;
}