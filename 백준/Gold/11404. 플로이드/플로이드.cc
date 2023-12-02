#include <iostream>
using namespace std;
const int MAX_DIST = 100000 * 99 * 50 + 1;

int n;
int dist[101][101];

int min(int a, int b) {return a < b ? a : b;}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int m; cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            dist[i][j] = i == j ? 0 : MAX_DIST;
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    for(int m=1; m<=n; m++)
        for(int s=1; s<=n; s++)
            for(int e=1; e<=n; e++)
                dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            cout << (dist[i][j] == MAX_DIST ? 0 : dist[i][j]) << ' ';
        cout << '\n';
    }
}