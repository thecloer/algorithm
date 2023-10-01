#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int box[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, M;
    cin >> M >> N;
    queue<pair<int,int>> Q;
    int unripe = 0, last = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) Q.push({i, j});
            else if(box[i][j] == 0) unripe++;
        }
    }
    if(unripe == 0) {
        cout << 0;
        return 0;
    }

    while(!Q.empty() && unripe > 0) {
        auto cur = Q.front(); Q.pop();
        for(int d=0; d<4; d++) {
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(box[nx][ny] != 0) continue;
            
            box[nx][ny] = box[cur.X][cur.Y] + 1;
            if(last < box[nx][ny]) last = box[nx][ny];
            if(--unripe == 0) break;
            Q.push({nx, ny});
        }
    }
    if(unripe > 0) cout << -1;
    else cout << last - 1;
}