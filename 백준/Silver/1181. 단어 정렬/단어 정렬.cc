#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string arr[20000];
bool cmp(const string &a, const string &b) {
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr + N, cmp);

    cout << arr[0] << '\n';
    for(int i = 1; i < N; i++)
        if(arr[i] != arr[i-1])
            cout << arr[i] << '\n';
}