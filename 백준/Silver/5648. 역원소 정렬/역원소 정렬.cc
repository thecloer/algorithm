#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[1000000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        while(!s.empty()) {
            arr[i] = 10*arr[i] + s.back() - '0';
            s.pop_back();
        }
    }
    sort(arr, arr+N);
    for(int i=0; i<N; i++) cout << arr[i] << '\n';
}