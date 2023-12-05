#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    pair<int, int> task[N];
    for(int i=0; i<N; i++)
        cin >> task[i].second >> task[i].first;
    sort(task, task+N);
    int ans = 0, t = 0;
    for(const auto &[e, s]:task) {
        if(s < t) continue;
        t = e;
        ans++;
    }
    cout << ans;
}