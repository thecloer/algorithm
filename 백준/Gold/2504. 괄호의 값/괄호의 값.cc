#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct e {
    char c;
    int v;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s; cin >> s;
    int ans = 0;
    stack<e> st;
    for(char c:s) {
        if(c == '(' || c == '[') st.push({c, 0});
        else {
            if(st.empty()) {
                ans = 0; 
                break;
            }

            int v = st.top().v;
            if(c == ')'){
                if(st.top().c != '(') {
                    ans = 0; 
                    break;
                }
                if(v == 0) v = 2;
                else v *= 2;
            } else if(c == ']'){
                if(st.top().c != '[') {
                    ans = 0; 
                    break;
                }
                if(v == 0) v = 3;
                else v *= 3;
            }

            st.pop();
            if(st.empty()) ans += v;
            else st.top().v += v;
        }
    }
    cout << ans;
}