#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b) {
    if(a.length() != b.length()) return a.length() < b.length();
    for(int i=0; i<a.length(); i++) {
        if(a[i] == b[i]) continue;
        return a[i] < b[i];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    unordered_set<string> W;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        W.insert(s);
    }
    int size = 0;
    string words[W.size()];
    for(const string &s : W) words[size++] = s;
    sort(words, words+size, cmp);
    for(const string &s : words) cout << s << '\n';
}