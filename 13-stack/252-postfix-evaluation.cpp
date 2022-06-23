#include <iostream>
#include<cstring>
using namespace std;
struct Node
{
int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t;
    t = new Node;

    if (t == NULL)
        cout << "stack is full" << endl;

    else
    {

        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
  int x = -1;
    if (top == NULL)
        cout << "empty stack";

    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

//----------------------------------------------------------
int isBalanced(char *exp)
{
     int i;
     for(i=0;exp[i]!='\0';i++)
     {
          if(exp[i]=='(')
          push(exp[i]);

          else if(exp[i]==')')
          {
               if(top==NULL)
               return 0;

               pop();
          }
     }
     if(top=NULL)
     return 1;

     else
     return 0;
}
//-------------------------------------------------------------
int pre(char x)
{
    if(x=='+'||x=='-')
    return 1;
    else if(x=='*' || x=='/')
    return 2;
    else if(x=='^')
    return 3;

    return 0;
}
int isOperand(char x)
{
    if(x=='+' ||x=='*' ||x=='-' || x=='/')
    return 0;
    else 
    return 1;
}

char *InToPost(char *infix)
{
    int i=0,j=0;
    char *postfix=new char[strlen(infix)+2];

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        postfix[j++]=infix[i++];

        else 
        {
            if(pre(infix[i])>pre(top->data))
            push(infix[i++]);

            else{
                postfix[j++]=pop();
            }
        }
    }

    while(top!=NULL)
    postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}
//----------------------------------------------

int Eval(char *postfix)
{
    int i;
    int x1,x2,r;

    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }

        else
        {
            x2=pop();x1=pop();

            switch(postfix[i])
            {
                case '+':r=x1+x2;break;
                case '-':r=x1-x2;break;
                case '*':r=x1*x2;break;
                case '/':r=x1/x2;break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
   char *postfix="234*+82/-";
cout<<"result is "<<Eval(postfix);

    return 0;
}