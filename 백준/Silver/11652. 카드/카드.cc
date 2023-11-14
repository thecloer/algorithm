#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[100000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    ll ans = arr[0];
    int cnt = 1, mxCnt = 0;
    for(int i=1; i<N; i++) {
        if(arr[i-1] == arr[i]) {
            cnt++;
            if(i == N-1 && mxCnt < cnt) ans = arr[i];
        } else {
            if(mxCnt < cnt) {
                ans = arr[i-1];
                mxCnt = cnt;
            }
            cnt = 1;
        }
    }
    cout << ans;
}