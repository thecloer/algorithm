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
    ll cur = 0, mx = 0;
    int cnt = 0, mxCnt = 0;
    for(int i=0; i<N; i++) {
        if(cur == arr[i]) cnt++;
        else {
            if(mxCnt < cnt) {
                mx = cur;
                mxCnt = cnt;
            }
            cur = arr[i];
            cnt = 1;
        }
    }
    if(mxCnt < cnt) {
        mx = cur;
        mxCnt = cnt;
    }
    cout << mx;
}