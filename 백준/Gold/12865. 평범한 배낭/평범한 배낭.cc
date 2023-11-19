#include <iostream>
#include <algorithm>
using namespace std;

struct product {int w, v;};
int maxValue[101][100001];
product products[101];

bool cmp(const product &p1, const product &p2) {
    return p1.w < p2.w;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K;
    for(int i=1; i<=N; i++) 
        cin >> products[i].w >> products[i].v;
    sort(products, products+N, cmp);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            maxValue[i][j] = maxValue[i-1][j];
            if(j >= products[i].w)
                maxValue[i][j] = max(maxValue[i][j], products[i].v + maxValue[i-1][j - products[i].w]);
        }
    }
    cout << maxValue[N][K];
}