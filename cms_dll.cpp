#include <iostream>
#include <string>
using namespace std;

struct Node {
    string donorName;
    double donationAmount;
    Node* next;
    Node* prev;
};

class CharityManagement {
    Node* head;

public:
    CharityManagement() {
        head = NULL;
    }

    void insertAtFirst() {
        Node* newNode = new Node;
        cin.ignore();
        cout << "Enter donor name: ";
        getline(cin, newNode->donorName);
        cout << "Enter donation amount: ";
        cin >> newNode->donationAmount;

        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        cout << "Donation added at the start.\n";
    }

    void insertAtLast() {
        Node* newNode = new Node;
        cin.ignore();
        cout << "Enter donor name: ";
        getline(cin, newNode->donorName);
        cout << "Enter donation amount: ";
        cin >> newNode->donationAmount;

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
        cout << "Donation added at the end.\n";
    }

    void displayDonations() const {
        if (head == NULL) {
            cout << "No donations recorded.\n";
            return;
        }

        Node* temp = head;
        cout << "\nDonations List:\n";
        cout << "Donor Name\tDonation Amount\n";
        while (temp != NULL) {
            cout << temp->donorName << "\t\tRs. " << temp->donationAmount << endl;
            temp = temp->next;
        }
    }

    void deleteFirst() {
        if (head == NULL) {
            cout << "No donations recorded.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        cout << "First donation removed.\n";
    }

    void deleteLast() {
        if (head == NULL) {
            cout << "No donations recorded.\n";
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
        cout << "Last donation removed.\n";
    }

    void searchDonation() {
        string donorName;
        cout << "Enter the donor name to search: ";
        cin.ignore();
        getline(cin, donorName);

        Node* temp = head;
        bool found = false;

        while (temp != NULL) {
            if (temp->donorName == donorName) {
                cout << "Donation found:\n";
                cout << "Donor Name: " << temp->donorName << ", Donation Amount: $" << temp->donationAmount << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Donation not found.\n";
        }
    }

    int countDonations() {
        Node* temp = head;
        int count = 0;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    ~CharityManagement() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    CharityManagement cms;
    int choice;

    do {
        cout << "\nSelect an option:\n";
        cout << "1. Add donation at start\n";
        cout << "2. Add donation at end\n";
        cout << "3. Display all donations\n";
        cout << "4. Remove first donation\n";
        cout << "5. Remove last donation\n";
        cout << "6. Search donation by donor name\n";
        cout << "7. Count donations\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cms.insertAtFirst();
                break;
            case 2:
                cms.insertAtLast();
                break;
            case 3:
                cms.displayDonations();
                break;
            case 4:
                cms.deleteFirst();
                break;
            case 5:
                cms.deleteLast();
                break;
            case 6:
                cms.searchDonation();
                break;
            case 7:
                cout << "Total donations: " << cms.countDonations() << endl;
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
