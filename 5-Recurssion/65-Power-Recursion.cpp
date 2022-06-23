#include <iostream>
using namespace std;
int power(int m, int n)
{
    if (n == 0)
        return 1;
    else
        return power(m, n - 1) * m;
}
int power1(int m, int n)
{

    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return power(m * m, n / 2);
        
    else
        return m * power(m * m, (n - 1) / 2);
}

int main()
{
    int r = power(2, 9);
    int s = power(2, 9);
    cout << r << endl;
    cout << s;
    return 0;
}