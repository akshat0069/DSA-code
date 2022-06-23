#include <iostream>
#include "queueCPP.h"
using namespace std;
class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }
    void CreateTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    int Height(Node *p);
};
void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);

    cout << "enter root value" << endl;
    cin >> x;

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "enter left child of " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "enter right child of " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}
void Tree::Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}
void Tree::Levelorder(struct Node *root)
{
    Queue q(100);

    cout << root->data << " ";
    q.enqueue(root);

    while (!q.isEmpty())
    {

        root = q.dequeue();
        if (root->lchild)
        {
            cout << root->lchild->data << " ";
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data << " ";
            q.enqueue(root->rchild);
        }
    }
}

int Tree ::Height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->rchild);
    y = Height(root->lchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int main()
{
    Tree t;
    t.CreateTree();
    cout << "Preorder " << endl;
    t.Preorder(t.root);
    cout<<endl;
    cout << "Inorder " << endl;
    t.Inorder(t.root);
    cout<<endl;
    cout << "Postorder " << endl;
    t.Postorder(t.root);

    return 0;
}