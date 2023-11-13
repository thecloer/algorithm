#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct lxy {int l, x, y;};
bool maze[5][5][5];
int dl[] = {1, -1, 0, 0, 0, 0};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, 1, -1};
int level[5] = {0, 1, 2, 3, 4};

bool OOB(int l, int x, int y) {
    return l<0 || l>4 || x<0 || x>4 || y<0 || y>4;
}
void rotate90(int stage) {
    int tmp[5][5];
    for(int x=0; x<5; x++)
        for(int y=0; y<5; y++)
            tmp[x][y] = maze[stage][x][y];
    for(int x=0; x<5; x++)
        for(int y=0; y<5; y++)
            maze[stage][y][4-x] = tmp[x][y];
}
int bfs() {
    bool vis[5][5][5] = {};
    queue<lxy> Q;
    Q.push({0, 0, 0});
    vis[0][0][0] = true;
    int dist = 0;
    while(!(Q.empty() || vis[4][4][4])) {
        dist++;
        for(int size = Q.size(); size--;) {
            lxy cur = Q.front(); Q.pop();
            for(int dir=6; dir--;) {
                int nl = cur.l + dl[dir];
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(OOB(nl, nx, ny)) continue;
                if(vis[nl][nx][ny]) continue;
                if(!maze[level[nl]][nx][ny]) continue;
                vis[nl][nx][ny] = true;
                Q.push({nl, nx, ny});
            }
        }
    }
    return vis[4][4][4] ? dist : -1;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            for(int k=0; k<5; k++)
                cin >> maze[i][j][k];
    
    int ans = -1;
    for(int rot = 0; rot < 1024; rot++) {
        int dirs[5];
        int tmp = rot;
        for(int stage = 0; stage < 5; stage++) {
            dirs[stage] = tmp & 3;
            tmp >>= 2;
        }
        for(int stage = 0; stage < 5; stage++)
            for(int i=0; i < dirs[stage]; i++)
                rotate90(stage);
        
        do {
            if(maze[level[0]][0][0] && maze[level[4]][4][4]) {
                int dist = bfs();
                if(dist < 0) continue;
                ans = (ans == -1) ? dist : min(ans, dist);
            }
        } while(next_permutation(level, level+5));

        for(int stage = 0; stage < 5; stage++)
            for(int i=0; dirs[stage] && i < 4-dirs[stage]; i++)
                rotate90(stage);
    }
    cout << ans;
}