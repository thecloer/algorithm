#include <iostream>
#include <queue>
#include <algorithm>
#define M first
#define V second
using namespace std;

int N, K;
pair<int,int> jewels[300000]; 
int capacity[300000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> jewels[i].M >> jewels[i].V;
    for(int i=0; i<K; i++) cin >> capacity[i];
    sort(jewels, jewels+N);
    sort(capacity, capacity+K);
    
    long long ans = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    for(int bag=0, i=0; bag<K; bag++) {
        while(i < N and jewels[i].M <= capacity[bag]) 
            pq.push(jewels[i++].V);
        
        if(pq.empty()) continue;
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}