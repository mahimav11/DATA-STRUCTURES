//Write a C++ program to design library system. Also perform the given operation. Use the concept of Array, Searching and Sorting technique. 
#include <iostream>
#include <string>
using namespace std;

class Books {
public:
    string name[10];
    string author[10];
    int edition[10];
    int price[10];
    int n;

    void inputBooks() 
    {
        cout << "Enter number of books: ";
        cin >> n;
        for (int i = 0; i < n; i++) 
        {
            cout << "Enter name of book " << i + 1 << ": ";
            cin >> name[i];
            cout << "Enter author of book " << i + 1 << ": ";
            cin >> author[i];
            cout << "Enter edition of book " << i + 1 << ": ";
            cin >> edition[i];
            cout << "Enter price of book " << i + 1 << ": ";
            cin >> price[i];
        }
    }

    void displayBooks() 
    {
        
        cout << "No\tName\tAuthor\tEdition\tPrice\n";
        for (int i = 0; i < n; i++) 
        {
            cout << i + 1 << "\t" << name[i] << "\t" << author[i] << "\t" << edition[i] << "\t" << price[i] << endl;
        }
    }

    void sortBooksByPrice() 
    {
        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n - 1 - i; j++) 
            {
                if (price[j] > price[j + 1]) 
                {
                    swap(price[j], price[j + 1]);
                    swap(name[j], name[j + 1]);
                    swap(author[j], author[j + 1]);
                    swap(edition[j], edition[j + 1]);
                }
            }
        }
    }

    void displayCheapBooks() 
    {
        cout << "\nBooks with price less than 500:\n";
        for (int i = 0; i < n; i++) 
        {
            if (price[i] < 500) 
            {
                cout << name[i] << " - " << price[i] << endl;
            }
        }
    }

    void displayUniquePrices() 
{
    // Sort the books by price to make it easier to detect duplicates
    sortBooksByPrice();

    // Array to store unique prices
    int uniquePrices[10];
    int uniqueCount = 0;

    // Store unique prices in the new array
    for (int i = 0; i < n; i++) 
    {
        if (i == n - 1 || price[i] != price[i + 1]) 
        {
            uniquePrices[uniqueCount] = price[i];
            uniqueCount++;
        }
        else 
        {
            // Skip the next element as it's a duplicate
            i++;
        }
    }

    // Now overwrite the original arrays with unique values only
    n = uniqueCount;
    for (int i = 0; i < n; i++) 
    {
        price[i] = uniquePrices[i];
    }

    // Display unique prices and their corresponding books
    cout << "\nBooks with unique prices:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << name[i] << " - " << price[i] << endl;
    }
}


};

int main() {
    Books books;
    books.inputBooks();
    
    cout << "\nBooks before sorting:\n";
    books.displayBooks();
    
    books.sortBooksByPrice();

    cout << "\nBooks after sorting by price (ascending order):\n";
    books.displayBooks();
    
    books.displayCheapBooks();
    books.displayUniquePrices();
    
    return 0;
}
