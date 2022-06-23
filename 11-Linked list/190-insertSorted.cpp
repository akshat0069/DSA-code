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

//-----------------------------------------

struct Node *LSearch(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node *RSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;

    if (key == p->data)
        return p;

    return RSearch(p->next, key);
}

struct Node *MoveToHead(struct Node *p, int key)
{
    struct Node *q;

    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
}

//------------------------------------
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if (index < 0 || index > count(p))
        return;

    t = new Node;
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

//----------------------------------------------
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = new Node;
    t->data = x;

    if (first == NULL)
        first = t;

    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if (p == first)
        {
            t->next = first;
            first = t;
        }

        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int main()
{

    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    SortedInsert(first,35);
    display(first);
    return 0;
}