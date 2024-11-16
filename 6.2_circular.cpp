#include <iostream>
using namespace std;

int queue[20];
int front = -1, rear = -1, ele;

void enQueue(int ele,int n) 
{
    if ((rear + 1) % n == front)
    {
        cout<<"Circular queue full\n";
    }
    else 
    {
        if (front == -1 && rear == -1) 
        {
            front = 0;
        }
        rear = (rear + 1) % n;
        cout<<"enter an element: ";
        cin>>ele;
        queue[rear] = ele;
    }
}

void deQueue(int n) 
{
    if (front == -1 && rear == -1) 
    {
        cout<<"Circular queue empty\n";
    } 
    else 
    {
        cout<<"element deleted is "<<queue[front]<<endl;
        if (front == rear) 
        {
            front = -1;
            rear = -1;
        } 
        else 
        {
            front = (front + 1) % n;
        }
    }
}

void display(int n) {
    if (front == -1 && rear == -1)
    {
        cout<<"Queue empty\n";
    } 
    else 
    {
        int i = front;
        cout<<"Elements in the queue: ";
        while (i != rear) 
        {
            cout<<"\n"<<i<<"\t"<<queue[i]<<"\n";
            i = (i + 1) % n ;
        }
        cout<<queue[rear];
    }
}

int main() 
{
    int ch, t, no,size;
    cout<<"enter queue size ";
    cin>>size;
    do {
        cout<<"\n1.enQueue()\n2.deQueue()\n3.display()\n4.Exit\n";
        cout<<"enter your choice: ";
        cin>>ch;

        switch (ch) 
        {
            case 1:
                enQueue(ele,size);
                break;
            case 2:
                deQueue(size);
                break;
            case 3:
                display(size);
                break;
            case 4:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Wrong Choice\n";
        }
        cout<<"[press 1 to continue] ";
        cin >>t;
    }
     while (t == 1);
    return 0;
}
