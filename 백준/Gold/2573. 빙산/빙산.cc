#include <iostream>
#include <queue>
using namespace std;

struct xy {int x, y;};
int N, M;
int board[300][300];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
queue<xy> B;

bool isOut(int x, int y) {return x<0||x>=N||y<0||y>=M;};
bool isOcean(int x, int y) {return board[x][y] == 0;};

void melting() {
    for(int size = B.size(); size--;) {
        xy cur = B.front(); B.pop();
        bool isBeach = false;
        for(int d=4; d--;) {
            int nx = cur.x + dx[d], ny = cur.y + dy[d];
            if(isOut(nx, ny) || isOcean(nx, ny)) continue;
            board[nx][ny]--;
            if(isOcean(nx, ny)) B.push({nx, ny});
            else isBeach = true;
        }
        if(isBeach) B.push(cur);
    }
}
int countLands() {
    int cnt = 0;
    bool vis[300][300] = {};
    queue<xy> Q;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(isOcean(i, j) || vis[i][j]) continue;
            cnt++;
            vis[i][j] = true;
            Q.push({i, j});
            while(!Q.empty()){
                xy cur = Q.front(); Q.pop();
                for(int d=4; d--;) {
                    int nx=cur.x+dx[d], ny=cur.y+dy[d];
                    if(isOut(nx, ny)) continue;
                    if(isOcean(nx, ny) || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> board[i][j];
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(!isOcean(i, j)) continue;
            for(int d=4; d--;) {
                int nx = i + dx[d], ny = j + dy[d];
                if(isOut(nx, ny) || isOcean(nx, ny)) continue;
                B.push({i, j});
                break;
            }
        }
    }
    int year = 0, cnt = 1;
    while(cnt == 1) {
        year++;
        melting();
        cnt = countLands();
    }
    if(cnt == 0) cout << 0;
    else cout << year;
}