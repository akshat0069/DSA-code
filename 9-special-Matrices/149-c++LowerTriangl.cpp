#include <iostream>
using namespace std;
class LowerTriangular
{
private:
    int n;
    int *A;

public:
//Default constructor
    LowerTriangular()
    {
        n = 2;
        A = new int[2*(2+1)/2];//n(n+1)/2
    }

    LowerTriangular(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }


    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~LowerTriangular()
    {
        delete[] A;
    }
};

void LowerTriangular::Set(int i, int j, int x)
{
    if (i >= j)
    {
        A[i*(i-1)/2+j-1] = x;//A[n*(j-1)-(j-1)*(j-1)/2+i-j] for column major
    }
}

int LowerTriangular::Get(int i, int j)
{
    if (i >= j)
        return A[i*(i-1)/2+j-1];//A[n*(j-1)-(j-1)*(j-1)/2+i-j]
    else
        return 0;
}

void LowerTriangular::Display()
{
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if (i >= j)
                cout << A[i*(i-1)/2+j-1] << " ";//A[n*(j-1)-(j-1)*(j-1)/2+i-j]

            else
                cout << "0"
                     << " ";
        }
        cout << endl;
    }
}
int main()
{
    int d;
    cout<<"enter dimensions"<<endl;
    cin>>d;

    LowerTriangular lm(d);

    int x;
    cout<<"enter all elements"<<endl;
    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            cin>>x;
            lm.Set(i,j,x);
        }
    }
    lm.Display();
    return 0;
}