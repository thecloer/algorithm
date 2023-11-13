#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<string> v(n);
    string tmp;
    for(auto &name:v) cin >> name >> tmp;
    sort(v.rbegin(), v.rend());
    for(int i=0; i<n; i++) {
        if(i != n-1 && v[i] == v[i+1]) i++;
        else cout << v[i] << '\n';
    }
}