#include <iostream>
using namespace std;
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void Insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL) //i.e. this is first node
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return; //i.e. stop
    }

    //it is not the first node
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;

        else if (key > t->data)
            t = t->rchild;

        else //i.e. key =t->data
            return;
    }
    //if we reach here ,that means t==NULL, and r is pointing on previous node
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
        r->lchild = p;

    else
        r->rchild = p;
};

void Inorder(struct Node *p)
{
    if (p) //p!=NULL
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
};

struct Node *Search(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
            return t;

        else if (key < t->data)
            t = t->lchild;

        else
            t = t->rchild;
    }
    return NULL;
};
int main()
{
    struct Node *temp;

    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);

    Inorder(root);
    cout << endl;

    temp = Search(20);

    if (temp != NULL)
        cout << "element is " << temp->data << " " << endl;
    else
        cout << "element not found " << endl;
    return 0;
}