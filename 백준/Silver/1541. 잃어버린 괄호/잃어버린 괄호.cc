#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int ans = 0, num = 0;
    bool isMinus = false;
    for(char c:s) {
        if(isdigit(c)) num = 10*num + c-'0';
        else if(isMinus) {
            ans -= num;
            num = 0;
        } else {
            ans += num;
            num = 0;
            if(c == '-') isMinus = true;
        }
    }
    ans += (isMinus ? -num : num);
    cout << ans;
}