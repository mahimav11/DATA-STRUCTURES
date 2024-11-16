// Implement C++ program for expression conversion infix to postfix using stack. 
#include <iostream>
#include <string>

using namespace std;

#define STACK_SIZE 50

// Stack to hold operators and parentheses
char stack[STACK_SIZE];
int top = -1;

// Push character onto stack
void push(char x) {
    if (top < STACK_SIZE - 1) {
        stack[++top] = x;
    } else {
        cout << "Stack Overflow" << endl;
    }
}

// Pop character from stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        cout << "Stack Underflow" << endl;
        return '\0';  // Return null character in case of underflow
    }
}

// Return precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return -1;  // Non-operator characters
    }
}

// Convert infix expression to postfix
void infixToPostfix(const string& infix) {
    char c;
    int i = 0;

    cout << "The postfix expression is: ";
    while (i < infix.length()) {
        c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            // Directly print operand (variable)
            cout << c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                cout << pop();
            }
            if (top != -1) {
                pop(); // Remove the '(' from the stack
            }
        } else { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                cout << pop();
            }
            push(c);
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        cout << pop();
    }

    cout << endl;
}

int main() {
    string infix;

    cout << "Enter the infix expression: ";
    cin >> infix;

    infixToPostfix(infix);

    return 0;
}
