#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;
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

//-----------QUESTION-1-------------------

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;

        q = q ? q->next : q; // if q!=NULL then q moves to next node

    } while (p && q && p != q); // till anyone becomes NULL or equal(i.e. loop is there)

    if (p == q)
        return 1;

    else
        return 0;
}
//-----------QUESTION-2 + QUESTION-4-------------------
int Delete(struct Node *p, int index)
{
    struct Node *dummy = new Node();
    dummy->next = p;

    struct Node *fast = dummy;
    struct Node *slow = dummy;

    for (int i = 0; i < index; i++)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    int x = slow->next->data;
    cout << "from last nth Node->data  is = " << x << endl;
    cout << endl;
    slow->next = slow->next->next;

    cout << "after deleting nth node from end of linked list it looks like  " << endl;
    display(first);
    return 0;
}
//-------------QUESTION-6-------------------

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }

        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
    display(first);
}
//--------------QUESTION-7-----------------
Node *Reverse(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    }

    return q;
}

bool pallindrome(struct Node *p)
{
    if (p == NULL || p->next == NULL)
        return 1;

    struct Node *fast = p;
    struct Node *slow = p;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;       // this will reach to middle
        fast = fast->next->next; // this will help in stopping loop
    }
    slow->next = Reverse(slow->next); // reversing half of linked list
    slow = slow->next;

    while (slow != NULL)
    {
        if (p->data != slow->data)
            return 0;

        p = p->next;
        slow = slow->next;
    }
    return 1;
}


int main()
{
    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 30, 40,50};
    create(A, 6);

  

    // // create a loop
    // t1 = first->next->next;             // pointing on 3rd node
    // t2 = first->next->next->next->next; // pointing on last node
    // t2->next = t1;                      // loop created
    // cout << isLoop(first) << endl;

    Delete(first, 3);
    cout<<endl;

    RemoveDuplicate(first);
    cout << endl;


    if (pallindrome(first))
        cout << "is pallindrome" << endl;
    else
        cout << "not pallindrome" << endl;

    return 0;
}