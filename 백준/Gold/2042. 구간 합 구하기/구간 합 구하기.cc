#include <iostream>
#define ll long long
using namespace std;

ll N, M, K, leafSize = 1;
ll segment[(1 << 21)];

inline int left(int node) {return 2*node;}
inline int right(int node) {return 2*node+1;}

ll sum(ll L, ll R, ll node, ll nodeL, ll nodeR) {
    if(R < nodeL || L > nodeR) return 0; 
    if(L <= nodeL and nodeR <= R) return segment[node];
    ll mid = (nodeL + nodeR) / 2;
    return sum(L, R, left(node), nodeL, mid) + sum(L, R, right(node), mid+1, nodeR);
}

void update(ll i, ll val) {
    i = leafSize + i - 1;
    segment[i] = val;
    while(i >>= 1)
        segment[i] = segment[left(i)] + segment[right(i)];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    while(leafSize < N) leafSize <<= 1;

    for(int i = leafSize; i < leafSize+N; i++) 
        cin >> segment[i];
    for(int i = leafSize-1; i > 0; i--)
        segment[i] = segment[left(i)] + segment[right(i)];
    
    ll Q = M+K;
    while(Q--) {
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1) update(b, c);
        else cout << sum(b, c, 1, 1, leafSize) << '\n';
    }
}