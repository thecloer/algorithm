#include <iostream>
#include <vector>
using namespace std;

int parent[51];
vector<int> parties[51];

int findRoot(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findRoot(parent[x]);
}
void merge(int a, int b) {
    a = findRoot(a); b = findRoot(b);
    if(a == b) return;
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, K; cin >> N >> M >> K;
    for(int i=1; i<=N; i++) parent[i] = i;
    while(K--) {
        int x; cin >> x;
        parent[x] = 0;
    }
    for(int p=0; p<M; p++) {
        int member; cin >> member;
        while(member--) {
            int x; cin >> x;
            parties[p].push_back(x);
        }
        for(int i=1; i<parties[p].size(); i++)
            merge(parties[p][0], parties[p][i]);
    }
    int ans = 0;
    for(int p=0; p<M; p++) 
        if(findRoot(parties[p][0])) ans++;
    cout << ans;
}