#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
//-------------------------------------

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

//----------------------------------------------
void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void display2(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        display2(p->next);
    }
}

//----------------------------------------------
int count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return (c);
}

int Rcount(struct Node *p)
{
    if (p != NULL)
        return Rcount(p->next) + 1;

    else
        return 0;
}

//----------------------------------------------
int sum(struct Node *p)
{
    int s = 0;
    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int Rsum(struct Node *p)
{
    if (p == 0)
        return 0;

    else
        return Rsum(p->next) + p->data;
}

//------------------------------------------
int Max(struct Node *p)
{
    int max = INT32_MIN;
    while (p)
    {
        if (p->data > max)

            max = p->data;

        p = p->next;
    }
    return max;
}

int Rmax(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return INT32_MIN;

    else
    {
        x = Rmax(p->next);

        if (x > p->data)
            return x;

        else
            return p->data;
    }
}

int main()
{
    int A[] = {3, 5, 7, 10, 15, 32, 3};
    create(A, 7);
    cout << "the maxmum number is " << Max(first) << endl;
    cout << "the maxmum number is " << Rmax(first) << endl;
    return 0;
}