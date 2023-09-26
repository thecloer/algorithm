#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int ans = 0;
    while(N--){
        string str; cin >> str;
        stack<char> s;
        for(char c:str) {
            if(!s.empty() && s.top() == c) s.pop();
            else s.push(c);
        }
        if(s.empty()) ans++;
    }
    cout << ans;
}