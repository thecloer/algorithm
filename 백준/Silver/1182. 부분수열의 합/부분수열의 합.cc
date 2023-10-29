#include <iostream>
using namespace std;

int N, S, ans;
int arr[20];
bool used[20];

void backtracking(int cur, int sum) {
    if(cur == N) {
        if(sum == S) ans++;
        return;
    }
    backtracking(cur+1, sum);
    backtracking(cur+1, sum + arr[cur]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    for(int i=0; i<N; i++) cin >> arr[i];
    backtracking(0, 0);
    if(S == 0) ans--;
    cout << ans;
}