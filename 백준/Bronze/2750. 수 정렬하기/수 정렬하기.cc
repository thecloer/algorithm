#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int &x:arr) cin >> x;
    sort(arr, arr + n);
    for(const int &x:arr) cout << x << '\n';
}