
#include <iostream>
using namespace std;
struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    cout << "enter size" << endl;
    cin >> st->size;
    st->top = -1;
    st->S = new int[st->size];
}
void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        cout << st.S[i] << " ";
    }
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        cout << "stack overflow" << endl;

    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        cout << "stack underflow";

    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int peek(struct Stack st, int index)//index is concidered from top of the stack
{
    int x = -1;
    if (st.top - index + 1 < 0)
        cout << "invalid index" << endl;

    else
    {
        x = st.S[st.top - index + 1];
    }
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;

    return 0;
}
int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;

    return 0;
}

int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top];

    return -1;
}
int main()
{
    struct Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    cout << "deleted value is " << pop(&st) << endl;
    // cout << " value at index is " << peek(st,2) << endl;

    Display(st);
    return 0;
}