#include <iostream>
#include <string>
using namespace std;

const int MAX_ORDERS = 100; // Maximum number of pizza orders

struct Pizza 
{
    string name;
    float price;
    int quantity;
};

class Queue 
{
private:
    Pizza queue[MAX_ORDERS]; // Array of Pizza objects
    int front = 0;
    int rear = -1;
    int count = 0;

public:
    // Function to add a pizza order to the queue
    void enQueue( const string& name, float price, int quantity) 
    {
        if (count < MAX_ORDERS) 
        {
          rear++;
            queue[rear] = {name, price, quantity}; // Directly assigning values
            count++;
            cout << "Order placed for " << name << endl;
            cout<<"Order id "<<rear+1;
        } 
        else 
        {
            cout << "Queue is full\n";
        }
    }

    // Function to remove a pizza order from the queue
    void deQueue() 
    {
        if (count == 0) 
        {
            cout << "Queue is empty\n";
        } else 
        {
            cout << "ORDER DISPENSED FOR: " << queue[front].name << endl;
             cout << "---------------------------------------------";
            cout<<"\nYOUR BILL RS. "<<queue[front].quantity*queue[front].price;
             cout << "\n---------------------------------------------\n";
           front++;
            count--;
        }
    }

    // Function to display all orders in the queue
    void display() const 
    {
        if (count == 0) 
        {
            cout << "Queue is empty\n";
        } else 
        {
            cout << "\nPizza ID\tPizza Name\tPrice\tQuantity\n";
            cout << "---------------------------------------------\n";
            int index = front;
            for (int i = 0; i < count; i++) 
            {
                cout << index+1 << "\t\t" << queue[index].name << "\t\t"
                     << queue[index].price << "\t" << queue[index].quantity << endl;
                index++;
            }
        }
    }
};

int main() 
{
    Queue q;
    int choice;
    
    do {
        cout << "\n1. Place Order\n2. Dispense Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, quantity;
                string name;
                float price;
                cout << "Enter Pizza Name: ";
                cin >> ws; // consume any leading whitespace
                getline(cin, name);
                cout << "Enter Pizza Price: ";
                cin >> price;
                cout << "Enter Pizza Quantity: ";
                cin >> quantity;

                q.enQueue(name, price, quantity);
                break;
            }
            case 2:
                q.deQueue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
