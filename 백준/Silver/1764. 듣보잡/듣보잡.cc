#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    unordered_set<string> st;
    vector<string> ans;
    while(N--) {
        string s; cin >> s;
        st.insert(s);
    }
    while(M--) {
        string s; cin >> s;
        if(st.find(s) != st.end())
            ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(string s:ans) cout << s << '\n';
}