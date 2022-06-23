#include<iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};
void missingElement(struct Array arr)
{
    int i;
    int dif=arr.A[0]-0;
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i]-i!=dif)
        {
            while(dif<arr.A[i]-i){
            cout<<"the missing element is "<<dif+i<<endl;
            dif++;
            }
                
        }
    
    }
}
int main(){
    struct Array arr={{6,7,8,9,11,12,15,16,17,18,19},20,11};
    missingElement(arr);
     return 0;
}