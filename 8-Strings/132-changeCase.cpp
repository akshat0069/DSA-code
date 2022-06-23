#include <iostream>
using namespace std;

int main()
{
    char A[] = "WELCOME";
    char B[] = "helloworld";
    char C[] = "weLCOMe";
    int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        A[i] = A[i] + 32;
    }
    cout << A << endl;
    cout<<endl;

    for (i = 0; B[i] != '\0'; i++)
    {
        B[i] = B[i] - 32;
    }
    cout << B << endl;
    cout<<endl;

    for (i = 0; C[i] != 0; i++)
    {
        if (C[i] >= 65 && C[i] <= 90)
        {
            C[i]=C[i]+32;
        }

         else if(C[i]>=97 && C[i]<=122)
        {
            C[i]=C[i]-32;
        }
    }
    cout<<C<<endl;
    return 0;
}