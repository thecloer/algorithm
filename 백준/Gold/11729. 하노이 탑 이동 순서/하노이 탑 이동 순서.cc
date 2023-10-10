#include <iostream>
using namespace std;

void move(int n, int from, int to) {
    if(n == 0) return;
    int nxt = n-1, tmp = 6-from-to;
    move(nxt, from, tmp);
    cout << from << ' ' << to << '\n';
    move(nxt, tmp, to);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    cout << (1 << N) - 1 << '\n';
    move(N, 1, 3);
}