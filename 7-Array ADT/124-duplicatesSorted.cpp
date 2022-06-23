#include <iostream>
using namespace std;
struct Array
{
    int A[30];
    int size;
    int length;
};

void findDuplicateM1(struct Array arr)
{
    int *H;
    H = new int[21]; //as 20 is highest number in list and index start from 0 ,therefore 21 is written,and its index will be 20 ,as we have to access 20 also

    //Initialize
    for (int i = 0; i < 21; i++)
    {
        H[i] = 0;
    }

    for (int i = 0; i < 21; i++)
    {
        H[arr.A[i]]++;
    }

    for (int i = 0; i < 21; i++)
    {
        if (H[i] > 1)
        {
            cout << "the duplicated number is " << i << " and number of duplicates is " << H[i] << endl;
        }
    }
    delete []H;
}

void findDuplicateM2(struct Array arr)
{
    int i,j,count;
   int n=arr.length;
    for(i=0;i<n;i++)
    {
        count=1;
       if(arr.A[i]!=-1)
       {
           for(j=i+1;j<n;j++)
           {
               if(arr.A[j]==arr.A[i])
               {
                   count++;
                   arr.A[j]=-1;
               }
           }
           if(count>1)
           {
               cout<<"the number is "<<arr.A[i]<<" and the number of duplicates are "<<count<<endl;
           }
       }

    }
}
int main()
{
    struct Array arr = {{3, 6, 8, 8, 10, 12, 15, 15, 15, 20}, 30, 10};
    findDuplicateM1(arr);
    findDuplicateM2(arr);
    return 0;
}