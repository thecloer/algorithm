#include <iostream>
#include <map>
using namespace std;

int N, S;
int num[40];
long long ans;
map<int, int> leftSum;

void BackTracking(bool isLeft, int cur, int end, int acc) {
    if(cur == end) {
        if(isLeft) leftSum[S - acc]++;
        else if(leftSum.count(acc)) ans += leftSum[acc];
        return;
    }
    BackTracking(isLeft, cur+1, end, acc);
    BackTracking(isLeft, cur+1, end, acc + num[cur]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    for(int i=0; i<N; i++) cin >> num[i];
    BackTracking(true, 0, N/2, 0);
    BackTracking(false, N/2, N, 0);
    if(S == 0) ans--;
    cout << ans;
}