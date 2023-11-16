#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct xy {int x, y;};
int N, M;
int board[8][8], tmp[8][8];
bool vis[8][8];
int mask[64];
vector<xy> space;
queue<xy> Q;
xy dxy[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0)
                space.push_back({i, j});
        }
    }
    int ans = 0;
    int spaceSize = space.size();
    for(int i=3; i<spaceSize; i++) mask[i] = 1;
    do {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                tmp[i][j] = board[i][j];
                if(board[i][j] == 2) {
                    vis[i][j] = true;
                    Q.push({i, j});
                } else vis[i][j] = false;
            }
        }
        for(int i=0; i<spaceSize; i++)
            if(mask[i] == 0) 
                tmp[space[i].x][space[i].y] = 1;

        while(!Q.empty()) {
            auto [x, y] = Q.front(); Q.pop();
            for(xy d:dxy) {
                int nx = x + d.x, ny = y + d.y;
                if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
                if(tmp[nx][ny] != 0) continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny] = true;
                tmp[nx][ny] = 2;
                Q.push({nx, ny});
            }
        }

        int cnt = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                if(tmp[i][j] == 0) cnt++;
        if(cnt > ans) ans = cnt;

        for(int i=0; i<spaceSize; i++)
            if(mask[i] == 0) 
                tmp[space[i].x][space[i].y] = 0;
    } while(next_permutation(mask, mask + spaceSize));
    cout << ans;
}