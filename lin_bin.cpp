#include <iostream>
using namespace std;

void binary_search()
{
    int low = 0, high = 4, mid = 0, key, flag = 0;
    int a[5] = {12, 13, 14, 15, 16};
    cout << "Enter the element to search in the array: ";
    cin >> key;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            flag = 1;
            break;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (flag == 1)
    {
        cout << key << " found at index " << mid << endl;
    }
    else
    {
        cout << key << " not found" << endl;
    }
}

void linear_search()
{
    int a[50];
    int n, flag = 0;
    int b, i;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the element you want to search: ";
    cin >> b;
    for (i = 0; i < n; i++)
    {
        if (a[i] == b)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "Element is present at index " << i << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}

int main()
{
    int ch, c;
    do
    {
        cout << "1. LINEAR SEARCH\n2. BINARY SEARCH\n3. EXIT\nENTER YOUR CHOICE: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Linear search\n";
            linear_search();
            break;
        case 2:
            cout << "Binary search\n";
            binary_search();
            break;
        case 3:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
        if (ch != 3)
        {
            cout << "[Press 1 to continue, any other key to exit]: ";
            cin >> c;
        }
        else
        {
            c = 0;
        }
    } while (c == 1);

    return 0;
}

