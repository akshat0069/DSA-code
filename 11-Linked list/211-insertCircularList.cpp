#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;

} * Head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    //creating head node
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;

    //creating remaining nodes
    last = Head;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *h)
{
    do
    {
        cout << h->data << " ";
        h = h->next;
    } while (h != Head);
    cout << endl;
};

void RDisplay(struct Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        cout << h->data << " ";
        RDisplay(h->next);
    }
    flag = 0;
}
//----------------------------------------------------------------------

int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > Length(p))
        return;
        
    if (index == 0)
    {
        t = new Node;
        t->data = x;

        if (Head == NULL)
        {
            Head = t;
            Head->next = t;
        }
        else
        {
            while (p->next != Head)
                p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }

    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
int main()
{

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    Insert(Head, 2, 10);
    Display(Head);

    return 0;
}