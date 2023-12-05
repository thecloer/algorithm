#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K;
    int coins[N];
    for(int i=0; i<N; i++) cin >> coins[i];
    
    int ans = 0, idx = N-1;
    while(K) {
        if(coins[idx] <= K) {
            ans += K / coins[idx];
            K %= coins[idx];
        }
        idx--;
    }
    cout << ans;
}