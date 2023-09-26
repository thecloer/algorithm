#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    while(N--){
        string str; cin >> str;
        stack<char> s;
        bool isValid = true;
        for(char c:str) {
            if(c == '(') s.push(c);
            else {
                if(s.empty() || s.top() != '(') {
                    isValid = false;
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty()) isValid = false;
        cout << (isValid ? "YES\n" : "NO\n");
    }
}