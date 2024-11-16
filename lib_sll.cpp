#include <iostream>
#include <string>
using namespace std;

struct Node {
    string title;
    string author;
    double price;
    string publisher;
    Node* next;
    Node* prev;
};

class Books {
    Node* head;

public:
    Books() {
     head = NULL;

    }
       //struct node *head;
    void insertAtFirst() {
        Node* newNode = new Node;
        cin.ignore();
        cout << "Enter book title ";
        getline(cin, newNode->title);
        cout << "Enter book author ";
        getline(cin, newNode->author);
        cout << "Enter book publisher ";
        getline(cin, newNode->publisher);
        cout << "Enter book price ";
        cin >> newNode->price;

        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        cout << "Book inserted at the start.\n";
    }

    void insertAtLast() {
        Node* newNode = new Node;
        cin.ignore();
        cout << "Enter book title ";
        getline(cin, newNode->title);
        cout << "Enter book author ";
        getline(cin, newNode->author);
        cout << "Enter book publisher ";
        getline(cin, newNode->publisher);
        cout << "Enter book price ";
        cin >> newNode->price;

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->prev = NULL;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Book inserted at the end.\n";
    }

    void insertAfter(int pos) {
        if (pos <= 0) {
            cout << "Position must be greater than 0.\n";
            return;
        }
        
        Node* temp = head;
        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range.\n";
            return;
        }

        Node* newNode = new Node;
       
        cin.ignore();
        cout << "Enter book title ";
        getline(cin, newNode->title);
        cout << "Enter book author ";
        getline(cin, newNode->author);
        cout << "Enter book publisher ";
        getline(cin, newNode->publisher);
        cout << "Enter book price ";
        cin >> newNode->price;
      
       

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        cout << "Book inserted after position " << pos << ".\n";
    }

    void display() const {
        if (head == NULL) {
            cout << "The list is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "\nBooks List:\n";
        cout << "Title\tAuthor\tPrice\tPublisher\n ";
        while (temp != NULL) {
            cout<<temp->title << "\t" << temp->author
                 << "\t Rs. " << temp->price << "\t" << temp->publisher << endl;
            temp = temp->next;
        }
    }

    void deleteFirst() {
        if (head == NULL) {
            cout << "The list is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        cout << "First book deleted.\n";
    }

    void deleteLast() {
        if (head == NULL) {
            cout << "The list is empty.\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
        }
        cout << "Last book deleted.\n";
    }

    void deleteAtPosition(int pos) {
        if (pos <= 0 || head == NULL) {
            cout << "Invalid position or the list is empty.\n";
            return;
        }

        Node* temp = head;
        if (pos == 1) {
            deleteFirst();
            return;
        }

        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range.\n";
            return;
        }

        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        delete temp;
        cout << "Book at position " << pos << " deleted.\n";
    }
     void search() {
        string title;
        cout << "Enter the book title to search: ";
        cin >> title;

        struct Node* temp = head;
        bool found = false;

        while (temp != NULL) {
            if (temp->title == title) {
                cout << "Book found: \n";
                cout << "Title: " << temp->title << ", Author: " << temp->author
                     << ", Price: " << temp->price << ", Publisher: " << temp->publisher << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Book not found.\n";
        }
    }
      int countBooks() 
      {
        struct Node* temp = head;
        int count = 0;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    ~Books() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Books b;
    int choice, pos;

    do {
        cout << "\nSelect an option:\n";
        cout << "1. Insert book at start\n";
        cout << "2. Insert book at end\n";
        cout << "3. Insert book after position\n";
        cout << "4. Display all books\n";
        cout << "5. Delete first book\n";
        cout << "6. Delete last book\n";
        cout << "7. Delete book at position\n";
        cout << "8.Search book\n";
        cout<<  "9.Count Books\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                b.insertAtFirst();
                break;
            case 2:
                b.insertAtLast();
                break;
            case 3:
                cout << "Enter the position after which to insert: ";
                cin >> pos;
                b.insertAfter(pos);
                break;
            case 4:
                b.display();
                break;
            case 5:
                b.deleteFirst();
                break;
            case 6:
                b.deleteLast();
                break;
            case 7:
                cout << "Enter position to delete: ";
                cin >> pos;
                b.deleteAtPosition(pos);
                break;
            case 8:
                b.search();
                break;
            case 9:
              cout<<"NO OF BOOKS "<<b.countBooks();
              break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                
        }
    } while (choice >0 && choice <11);

    return 0;
}
