#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct xy {int x, y;};
char board[12][6];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool OOB(int x, int y) {return x<0||x>11||y<0||y>5;}
bool popPuyo() {
    bool isPopped = false;
    bool vis[12][6] = {};
    for(int i=0; i<12; i++) {
        for(int j=0; j<6; j++) {
            if(board[i][j] == '.' || vis[i][j]) continue;
            vector<xy> tmp;
            queue<xy> Q;
            Q.push({i, j});
            tmp.push_back({i, j});
            vis[i][j] = true;
            while(!Q.empty()) {
                xy cur = Q.front(); Q.pop();
                for(int dir = 4; dir--;) {
                    int nx = cur.x+dx[dir], ny = cur.y+dy[dir];
                    if(OOB(nx, ny) || vis[nx][ny]) continue;
                    if(board[nx][ny] != board[cur.x][cur.y]) continue;
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                    tmp.push_back({nx, ny});
                }
            }
            if(tmp.size() < 4) continue;
            for(auto [x, y] : tmp) board[x][y] = '.';
            isPopped = true;
        }
    }
    
    return isPopped;
}
void downBoard() {
    for(int y=0; y<6; y++) {
        int top = 11;
        while(top >= 0 && board[top][y] != '.') top--;
        for(int x=top-1; x>=0; x--) {
            if(board[x][y] == '.') continue;
            board[top--][y] = board[x][y];
            board[x][y] = '.';
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<12; i++)
        for(int j=0; j<6; j++)
            cin >> board[i][j];
    int seq = 0;
    while(true) {
        if(!popPuyo()) break;
        downBoard();
        seq++;
    }
    cout << seq;
}