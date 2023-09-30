#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    deque<int> dq;
    for(int i=1; i<=N; i++) 
        dq.push_back(i);

    int ans = 0;
    while(M--) {
        int x; cin >> x;
        int pos = find(dq.begin(), dq.end(), x) - dq.begin();
        int bPos = dq.size() - pos;
        if(pos < bPos) {
            while(pos--) {
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
        } else {
            while(bPos--) {
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
        }
        dq.pop_front();
    }
    cout << ans;
}