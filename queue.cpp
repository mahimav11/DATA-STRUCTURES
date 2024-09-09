#include <iostream>
using namespace std; 
class queues
{
    private:
        int rear=-1;
        int front=-1;
        int queue[10],ele;
    public:

    void enQueue(int ele,int x)
    {
   
    if(rear==x-1)
    {
        cout<<"Queue is full\n";
    }
    else
    {
        rear++;
        queue[rear]=ele;
    }
    }
    void deQueue()
    {
    if(rear==front)
    {
        cout<<"Queue is empty\n";
    }
    else
    {
        front++;
        ele=queue[front];
        cout<<"Deleted element is "<<ele;
     }
    } 
     void display()
    {
    int i;
    if(rear==front)
    {
        cout<<"Queue is empty";
    }
    else
    {
        for(i=front+1;i<=rear;i++)
        {
            cout<<queue[i]<<"\t";
        }
    }
    }
};
int main()
{   queues q;
    int i,ch,k,e,size;
    cout<<"enter the size of queue ";
    cin>>size;
    
    do{
        cout<<"1.enQueue\n2.deQueue\n3.display\n";
        cout<<"enter choice :";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"enQueue ";
                   cin>>e;
                   q.enQueue(e,size);
                   break;
            case 2:cout<<"deQueue ";
                   q.deQueue();
                   break;
            case 3:cout<<"display \n";
                   q.display();
                   break;
            default:cout<<"wrong choice\n";
        }
    }
    while(ch>=1 && ch<=3);
    return 0;
}
