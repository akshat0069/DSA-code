#include <iostream>
using namespace std;

int main()
{
    int *p, *q;
    p = new int[5];
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    for (int i = 0; i < 5; i++)
        cout << p[i] << endl;

    q = new int[10];

    for (int i = 0; i < 5; i++)
        q[i] = p[i];

    delete[] p;
    for (int i = 0; i < 5; i++)

        cout << q[i] << endl;

    p = q;
    q = NULL;
    return 0;
}