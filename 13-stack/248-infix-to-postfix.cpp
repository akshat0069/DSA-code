// #include <iostream>
// #include<cstring>
// using namespace std;
// struct Node
// {
//  char data;
//     struct Node *next;
// } *top = NULL;

// void push(char x)
// {
//     struct Node *t;
//     t = new Node;

//     if (t == NULL)
//         cout << "stack is full" << endl;

//     else
//     {

//         t->data = x;
//         t->next = top;
//         top = t;
//     }
// }

// char pop()
// {
//     struct Node *t;
//     char x = -1;
//     if (top == NULL)
//         cout << "empty stack";

//     else
//     {
//         t = top;
//         top = top->next;
//         x = t->data;
//         delete t;
//     }
//     return x;
// }

// void Display()
// {
//     struct Node *p;
//     p = top;
//     while (p != NULL)
//     {
//         cout << p->data << " ";
//         p = p->next;
//     }
// }

// //----------------------------------------------------------
// int isBalanced(char *exp)
// {
//      int i;
//      for(i=0;exp[i]!='\0';i++)
//      {
//           if(exp[i]=='(')
//           push(exp[i]);

//           else if(exp[i]==')')
//           {
//                if(top==NULL)
//                return 0;

//                pop();
//           }
//      }
//      if(top=NULL)
//      return 1;

//      else
//      return 0;
// }

// //-------------------------------------------------------------------------------

// int pre(char x)
// {
//     if(x=='+'||x=='-')
//     return 1;
//     else if(x=='*' || x=='/')
//     return 2;

//     return 0;
// }

// int isOperand(char x)
// {
//     if(x=='+' ||x=='*' ||x=='-' || x=='/')
//     return 0;
//     else 
//     return 1;
// }

// char *InToPost(char *infix)
// {
//     int i=0,j=0;
//     char *postfix=new char[strlen(infix)+2];

//     while(infix[i]!='\0')
//     {
//         if(isOperand(infix[i]))
//         postfix[j++]=infix[i++];

//         else 
//         {
//             if(pre(infix[i])>pre(top->data))
//             push(infix[i++]);

//             else{
//                 postfix[j++]=pop();
//             }
//         }
//     }

//     while(top!=NULL)
//     postfix[j++]=pop();
//     postfix[j]='\0';
//     return postfix;
// }
// int main()
// {
//   char *infix="a+b*c-d/e";
//   push('#');
//   char *postfix=InToPost(infix);

//   cout<<postfix;

//     return 0;
// }
#include <iostream>
#include<cstring>
#include <stack>

using namespace std;
 
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}
 
int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}
 
int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}
 
char* convert(char* infix){
    char* postfix = new char [strlen(infix) + 1];
 
    stack<char> stk;
 
    int i = 0;
    int j = 0;
 
    while (infix[i] != '\0'){
        if (isOperand(infix[i])){
            postfix[j++] = infix[i++];
        } else {
            if (stk.empty() || outPrecedence(infix[i]) > inPrecedence(stk.top())){
                stk.push(infix[i++]);
            } else if (outPrecedence(infix[i]) == inPrecedence(stk.top())){
                stk.pop();
            }
            else {
                postfix[j++] = stk.top();
                stk.pop();
            }
        }
    }
 
    while (! stk.empty() && stk.top() != ')'){
        postfix[j++] = stk.top();
        stk.pop();
    }
 
    postfix[j] = '\0';
 
    return postfix;
 
}
 
 
int main() {
 
    char infix[] = "A+B/C*(D-F)^F*G/H";
 
    cout << convert(infix) << endl;
 
}