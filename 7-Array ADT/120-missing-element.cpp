#include <iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};

void fun2(struct Array arr)
{
    int l=arr.A[0];
    int dif=l-0;
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]-i!=dif)
        {
            cout<<"the missing element is "<<i+dif<<endl;
            break;
        }
    }
}

void fun1(struct Array arr)
{
  int n = arr.A[arr.length - 1];
    int s;
    s = (n * (n + 1)) / 2;

    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum = sum + arr.A[i];
    }

    cout << "the missing element is " << s - sum<<endl;
}
int main()

{
    struct Array arr1 = {{1,2,3,4,5,6,8,9,10,11,12}, 20, 11};
    struct Array arr2 = {{6,7,8,9,10,11,13,14,15,16,17}, 20, 11};
    fun1(arr1); 
    fun2(arr2); 
    return 0;
}