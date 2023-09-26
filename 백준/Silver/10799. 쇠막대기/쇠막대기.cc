#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string l;
    cin >> l;

    stack<char> S;
    int ans = 0;
    bool isLaser = true;
    
    for(char c:l) {
        if(c == '(') {
            S.push(c);
            isLaser = true;
        } else {
            S.pop();
            if(isLaser) {
                isLaser = false;
                ans += S.size();
            } else ans++;
        }
    }
    cout << ans;
}