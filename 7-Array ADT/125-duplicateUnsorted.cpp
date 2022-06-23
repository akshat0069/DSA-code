#include<iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};

void findDuplicate(struct Array arr){
    int *H;
    int i;
    H=new int[8];
    for(i=0;i<=8;i++)
    {
      H[i]=-1;
    }

    for(i=0;i<8;i++)
    {
      H[arr.A[i]]++;
    }

    for(i=0;i<=8;i++)
    {
        if(H[i]>0)
        {
            cout<<"the number is "<<i<<" and number of duplicates are "<<H[i]+1<<endl;
        }
    }

    delete []H;
}
int main(){
    struct Array arr = {{8,3,6,4,6,5,6,8,2,7}, 20, 10};
    findDuplicate(arr);
     return 0;
}