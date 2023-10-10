#include <iostream>
using namespace std;

int z(int n, int start, int r, int c) {
    if(n == 0) return start;
    int half = 1 << --n;
    int area = half*half;
    if(r >= half) {
        r -= half;
        start += 2*area;
    }
    if(c >= half) {
        c -= half;
        start += area;
    }
    return z(n, start, r, c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c; cin >> N >> r >> c;
    cout << z(N, 0, r, c);
}