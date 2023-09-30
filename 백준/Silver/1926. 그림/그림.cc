#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int graph[501][501];
bool vis[501][501];
int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1 , 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> graph[i][j];

    int cnt=0, wide=0;
    queue<pair<int,int>> Q;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(vis[i][j] || graph[i][j] == 0) continue;
            cnt++;
            int area = 0;
            vis[i][j] = 1;
            Q.push({i, j});
            while(!Q.empty()) {
                area++;
                auto cur = Q.front(); Q.pop();
                for(int d=0; d<4; d++) {
                    int nx = cur.X + dx[d];
                    int ny = cur.Y + dy[d];

                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if(vis[nx][ny] || graph[nx][ny] != 1) continue;
                    
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            if(area > wide) wide = area;
        }
    }

    cout << cnt << '\n' << wide;
}