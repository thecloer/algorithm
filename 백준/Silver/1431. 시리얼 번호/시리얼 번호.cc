#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b) {
    if(a.length() != b.length()) return a.length() < b.length();
    int n = 0;
    for(char c:a) if(isdigit(c)) n += c - '0';
    for(char c:b) if(isdigit(c)) n -= c - '0';
    if(n) return n < 0;
    return a < b;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector<string> v(N);
    for(string &id:v) cin >> id;
    sort(v.begin(), v.end(), cmp);
    for(const string &id:v) cout << id << '\n';
}