#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    vector<string> v;
    for(int i=0; i<s.length(); i++) 
        v.push_back(s.substr(i));
    sort(v.begin(), v.end());
    for(string sub:v) 
        cout << sub << '\n';
}