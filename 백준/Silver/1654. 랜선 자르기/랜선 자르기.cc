#include <iostream>
#define ll long long
using namespace std;

int K, N;
ll wires[10000];

ll cut(ll len) {
    ll cnt = 0;
    for(int i=0; i<K; i++) {
        if(wires[i] < len) continue;
        cnt += wires[i] / len;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> K >> N;
    ll mn = 0, mx = 0;
    for(int i=0; i<K; i++) {
        cin >> wires[i];
        if(wires[i] > mx) mx = wires[i];
    }
    
    ll len;
    while(mn < mx) {
        len = (mn + mx) >> 1;
        if(len == mn) break;
        if(cut(len) < N) mx = len;
        else mn = len;
    }
    if(cut(len + 1) < N) cout << len;
    else cout << len + 1;
}