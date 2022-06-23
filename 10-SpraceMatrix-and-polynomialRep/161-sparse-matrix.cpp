#include <iostream>
using namespace std;
struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *e;
};

void Create(struct Sparse *s)
{
    cout << "enter dimensions" << endl;
    cin >> s->m >> s->n;

    cout << "enter number of non zero elements" << endl;
    cin >> s->num;

    s->e = new Element[s->num];

    cout << "enter all non zero elements" << endl;
    for (int i = 0; i < s->num; i++)
    {
        cin >> s->e[i].i >> s->e[i].j >> s->e[i].x;
    }
}

void Display(struct Sparse s)
{
    int i, j, k = 0;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
                cout << s.e[k++].x << " ";

            else
                cout << "0"
                     << " ";
        }
        cout << endl;
    }
}
int main()
{
    struct Sparse s;
    Create(&s);
    Display(s);
    return 0;
}