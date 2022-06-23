#include <iostream> 
using namespace std; 
void swap(int *x, int *y) 
{ 
int temp = *x; 
*x = *y; 
*y = temp; 
} 
void BubbleSort(int A[], int n) 
{
int i, j, flag = 0; 
for (i = 0; i < n - 1; i++) 
{ 
flag = 0; 
for (j = 0; j < n - i - 1; j++) 
{ 
if (A[j] > A[j + 1]) 
{ 
swap(&A[j], &A[j + 1]); 
flag = 1; 
} 
} 
if(flag==0) 
break; 
} 
} 
// --------------------------------------------------------------------------- ---- 
void SelectionSort(int A[],int n) 
{ 
int i,j,k; 
for(i=0;i<n-1;i++) 
{ 
for(j=k=i;j<n;j++) 
{ 
if(A[j]<A[k]) 
k=j; 
} 
swap(&A[i],&A[k]); 
} 
} 
int main() 
{ 
int A[] = {11,13,7,2,86,9,4,5,10,3}, n = 10,i; 
BubbleSort(A,10); 
for ( i = 0; i <10; i++) 
cout << A[i] << " "; 
cout<<endl; 
// InsertionSort(A,10); 
SelectionSort(A,10); 
for ( i = 0; i <10; i++) 
cout << A[i] << " "; 
cout<<endl; 
return 0; 
}
