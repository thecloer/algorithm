#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    stack<char> S;
    string infix, postfix; 
    cin >> infix;
    for(char c:infix) {
        if('A' <= c and c <= 'Z') postfix += c;
        else if(c == '(') S.push(c);
        else if(c == ')') {
            while(not (S.empty() or S.top() == '(')) {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
        else {
            while(not S.empty() and priority(c) <= priority(S.top())) {
                postfix += S.top();
                S.pop();
            }
            S.push(c);
        }
    }
    while(not S.empty()) {
        postfix += S.top();
        S.pop();
    }
    cout << postfix;
}