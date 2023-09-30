#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define X first
#define Y second

int graph[102][102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        string tmp; cin >> tmp;
        int j=1;
        for(char c:tmp) graph[i][j++] = c - '0';
    }

    queue<pair<int,int>> Q;
    vis[1][1] = 1;
    Q.push({1, 1});
    while(!Q.empty() && graph[N][M] == 1) {
        auto cur = Q.front(); Q.pop();
        for(int d=0; d<4; d++) {
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];
            if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if(vis[nx][ny] || graph[nx][ny] != 1) continue;

            graph[nx][ny] = graph[cur.X][cur.Y] + 1;
            if(nx == N && ny == M) break;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    cout << graph[N][M];
}