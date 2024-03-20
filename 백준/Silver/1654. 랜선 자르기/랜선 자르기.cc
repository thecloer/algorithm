#include <iostream>
#define ll long long
using namespace std;

int K, N;
int wires[10000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> K >> N;
    ll s = 0, e, m;
    for(int i=0; i<K; i++) {
        cin >> wires[i];
        if(wires[i] > e) e = wires[i];
    }
    
    while(s < e) {
        m = (s + e) >> 1;
        if(s == m) m++;

        ll cnt = 0;
        for(int i=0; i<K; i++) cnt += wires[i] / m;

        if(cnt < N) e = m - 1;
        else s = m;
    }
    cout << s;
}

