#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int precedence(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

int main() {
    string str;
    string postfix = "";

    getline(cin >> ws, str);

    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (isalpha(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {

            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }
        else {

            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix: " << postfix;

    return 0;
}
