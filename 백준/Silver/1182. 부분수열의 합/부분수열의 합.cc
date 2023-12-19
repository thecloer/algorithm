#include <iostream>
using namespace std;

int N, S, ans;
int num[40];

void backTracking(int cur, int acc) {
    if(cur == N) {
        if(acc == S) ans++;
        return;
    }
    backTracking(cur+1, acc);
    backTracking(cur+1, acc + num[cur]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    for(int i=0; i<N; i++) cin >> num[i];
    backTracking(0, 0);
    if(S == 0) ans--;
    cout << ans;
}