#include<iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};

void findMaxMin(struct Array arr)
{
    int max=arr.A[0];
    int min=arr.A[0];
    int i;
    int n=arr.length;
    for(i=0;i<n;i++)
    {
        if(arr.A[i]<min)
        {
            min=arr.A[i];
        }
        else if(arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    cout<<"maximum value is "<<max<<endl;
    cout<<"minimum value is "<<min<<endl;
}
int main(){
    struct Array arr1={{5,8,3,9,6,2,13,7,-1,4},20,10};
    struct Array arr2={{1,2,3,4,5,6,7,8,9,10},20,10};
    findMaxMin(arr1);
    findMaxMin(arr2);
     return 0;
}