#include <iostream>
#include <queue>
using namespace std;

struct xy {int x, y;};
int N, M, C;
bool cheese[102][102];
bool vis[102][102];
int hit[102][102];
xy dxy[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void air() {
    for(int i=0; i<N+2; i++)
        for(int j=0; j<M+2; j++)
            vis[i][j] = false;
    queue<xy> Q;
    Q.push({0, 0});
    vis[0][0] = true;
    while(not Q.empty()) {
        const auto [x, y] = Q.front(); Q.pop();
        for(const auto [dx, dy]:dxy) {
            int nx = x + dx, ny = y + dy;
            if(nx<0 or nx>N+1 or ny<0 or ny>M+1) continue;
            if(vis[nx][ny]) continue;

            if(cheese[nx][ny]) hit[nx][ny]++;
            else {
                vis[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
}
int melt() {
    int cnt = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(cheese[i][j] and hit[i][j]) {
                if(hit[i][j] < 2) hit[i][j] = 0;
                else {
                    cnt++;
                    cheese[i][j] = false;
                }
            }
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0); cin.tie();
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> cheese[i][j];
            if(cheese[i][j]) C++;
        }
    }
    int sec = 0;
    while(C) {
        sec++;
        air();
        C -= melt();
    }
    cout << sec;
}