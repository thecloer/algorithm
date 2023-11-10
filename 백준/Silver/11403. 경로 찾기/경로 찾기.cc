#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    bool board[N][N], vis[N][N];
	for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
            vis[i][j] = false;
        }
    }
    queue<int> Q;
    for(int start=0; start<N; start++) {
        Q.push(start);
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for(int nx=0; nx<N; nx++) {
                if(!board[x][nx]) continue;
                if(vis[start][nx]) continue;
                vis[start][nx] = true;
                Q.push(nx);
            }
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            cout << vis[i][j] << ' ';
        cout << '\n';
    }
}