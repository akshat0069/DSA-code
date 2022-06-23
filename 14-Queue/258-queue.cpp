#include<iostream>
using namespace std;
class Queue
{
    private:
    int size;
    int front;
    int rear;
    int *Q;

public:
Queue(){front=rear=-1;size=10;Q=new int [size];}

Queue(int size){front=rear=-1;this->size=size;Q=new int[this->size];}

void enqueue(int x);
int dequeue();
void Display();
};

void Queue:: enqueue(int x)
{
    if(rear==size-1)
    cout<<"queue is full"<<endl;

    else
    rear++;
    Q[rear]=x;
}

int Queue::dequeue()
{
    int x=-1;
    if(front==rear)
    cout<<"Queue is empty"<<endl;

    else
    {
        //x=Q[front+1];front++;
        front ++;
        x=Q[front];
    }
    return x;
}

void Queue::Display()
{
    for(int i=front+1;i<=rear;i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}
int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.Display();

    q.dequeue();
    q.Display();
     return 0;
}