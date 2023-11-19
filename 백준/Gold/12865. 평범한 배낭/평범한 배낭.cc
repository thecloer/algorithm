#include <iostream>
using namespace std;

struct product {int w, v;};
int maxValue[101][100001];
product products[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K;
    for(int i=1; i<=N; i++) 
        cin >> products[i].w >> products[i].v;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            maxValue[i][j] = maxValue[i-1][j];
            if(j >= products[i].w)
                maxValue[i][j] = max(maxValue[i][j], 
                                    products[i].v + maxValue[i-1][j - products[i].w]);
        }
    }
    cout << maxValue[N][K];
}