#include <iostream>
using namespace std;

int prefixSum[100001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> prefixSum[i];
        prefixSum[i] += prefixSum[i-1];
    }
    while(M--) {
        int s, e; cin >> s >> e;
        cout << prefixSum[e] - prefixSum[s-1] << '\n';
    }
}