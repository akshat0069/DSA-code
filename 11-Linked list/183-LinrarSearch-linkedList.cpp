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

struct Node* RSearch(struct Node *p,int key)
{
    if(p==NULL)
    return NULL;

    if(key==p->data)
    return p;

    return RSearch(p->next,key);
}

struct Node *MoveToHead(struct Node *p,int key)
{
    struct Node *q;

    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
}
int main()
{
    struct Node *temp1,*temp2,*temp3;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
//----------------------------------------
    temp1 = LSearch(first, 25);
    if (temp1)
        cout << "the key is found " << temp1->data << endl;

    else
        cout << "key not found " << endl;
//----------------------------------------
    temp2 = RSearch(first, 32);
    if (temp2)
        cout << "the key is found " << temp2->data << endl;

    else
        cout << "key not found " << endl;
//---------------------------------------
    temp3 = MoveToHead(first, 32);
    if (temp3)
        cout << "the key is found " << temp3->data << endl;

    else
        cout << "key not found " << endl;

        display(first);
    return 0;
}