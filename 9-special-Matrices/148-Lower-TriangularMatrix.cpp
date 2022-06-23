//------------------------------------ROW MAJOR METHOD--------------------------
#include <iostream>
using namespace std;
struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[i * (i - 1) / 2 + j - 1] = x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i >= j)
        return m.A[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
                cout << m.A[i * (i - 1) / 2 + j - 1] << " ";

            else
                cout << "0"
                     << " ";
        }
        cout << endl;
    }
}
int main()
{
    struct Matrix m;
    int i, j, x;
    cout << "enter dimension" << endl;
    cin >> m.n;                         // i.e. n
    m.A = new int[m.n * (m.n + 1) / 2]; //formulae from tut 146 i.e. n(n+1)/2 i.e. number of non zero elements

    cout << "enter all elements" << endl;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            cin >> x;
            Set(&m, i, j, x);
        }
    }
    cout << endl;
    Display(m);
    return 0;
}