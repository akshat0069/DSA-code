#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

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

void display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
       p= p->next;
    }
}

void display2(struct Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        display2(p->next);
    }
}

int count(struct Node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return (c);
}

int Rcount(struct Node *p)
{
    if(p!=NULL)
    return Rcount(p->next ) +1;
    
    else 
    return 0;
}

int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}

int Rsum(struct Node *p)
{
    if(p==0)
    return 0;

    else
    return Rsum(p->next)+p->data;
}
int main()
{
    int A[] = {3, 5, 7, 10, 15};
    create(A,5);
    cout<<"the length is "<<count(first)<<endl;
    cout<<"the length is "<<Rcount(first)<<endl;
    cout<<"the sum is "<<sum(first)<<endl;
    cout<<"the sum is "<<Rsum(first)<<endl;
    return 0;
}