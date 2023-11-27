#include <iostream>
using namespace std;

int sum[1001], num[1001];
int max(int a, int b) {return a > b ? a : b;}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> num[i];
    for(int i=0; i<N; i++) {
        for(int j=i-1; j>=0; j--)
            if(num[j] < num[i])
                sum[i] = max(sum[i], sum[j]);
        sum[i] += num[i];
    }
    int ans = 0;
    for(int i=0; i<N; i++) ans = max(ans, sum[i]);
    cout << ans;
}