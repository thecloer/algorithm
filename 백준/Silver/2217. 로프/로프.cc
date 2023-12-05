#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    long long rope[N];
    for(int i=0; i<N; i++) cin >> rope[i];
    sort(rope, rope+N);
    long long ans = 0;
    for(int i=0; i<N; i++) ans = max(ans, rope[i] * (N-i));
    cout << ans;
}