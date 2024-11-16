//Write C++ program with functions. To check whether given string is palindrome or not that uses a stack to determine whether a string is a palindrome
#include <iostream>
#include <cstring>
using namespace std;

char stack[30];
int top = -1;

void push(char ele) {
    if (top == 29) {  // Maximum stack size is 30
        cout << "STACK OVERFLOW\n";
    } else {
        top++;
        stack[top] = ele;
    }
}

char pop() {
    if (top == -1) {
        cout << "STACK UNDERFLOW\n";
        return '\0';  // Return null character if stack is empty
    } else {
        char ele = stack[top];
        top--;
        return ele;
    }
}

bool isPalindrome(char str[]) {
    int len = strlen(str);

    // Push all characters of the string into the stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    // Compare the stack with the original string
    for (int i = 0; i < len; i++) {
        if (str[i] != pop()) {
            return false;  // If any character doesn't match, it's not a palindrome
        }
    }
    return true;
}

int main() {
    char m[30];
    cout << "Enter string to check: ";
    cin >> m;

    if (isPalindrome(m)) {
        cout << "String is a palindrome\n";
    } else {
        cout << "String is not a palindrome\n";
    }

    return 0;
}
