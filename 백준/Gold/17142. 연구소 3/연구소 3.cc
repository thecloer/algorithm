#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_DIST = 2500;

struct xy {int x, y;};
int N, M, C;
int board[50][50];
int vis[50][50];
bool mask[10];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(queue<xy> &Q, int mark) {
    int rest = C;
    int sec = 0;
    while(not Q.empty()) {
        sec++;
        for(int size=Q.size(); size--;) {
            const auto [x, y] = Q.front(); Q.pop();
            for(int d=4; d--;) {
                int nx = x + dx[d], ny = y + dy[d];
                if(nx<0||nx>=N||ny<0||ny>=N) continue;
                if(vis[nx][ny] == mark) continue;
                if(board[nx][ny] == 1) continue;
                
                vis[nx][ny] = mark;
                Q.push({nx ,ny});
                if(board[nx][ny] == 0 and not --rest) return sec;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    vector<xy> virus;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) C++;
            else if(board[i][j] == 2)
                virus.push_back({i, j});
        }
    }
    if(C == 0) {
        cout << 0;
        return 0;
    }

    int ans = MAX_DIST, mark = 0;
    for(int i=M; i<virus.size(); i++) mask[i] = true;
    
    do {
        mark++;
        queue<xy> Q;
        for(int i=0; i<virus.size(); i++) {
            if(mask[i]) continue;
            Q.push(virus[i]);
            vis[virus[i].x][virus[i].y] = mark;
        }
        int sec = bfs(Q, mark);
        if(sec != -1) ans = min(ans, sec);
    } while(next_permutation(mask, mask+virus.size()));

    cout << (ans == MAX_DIST ? -1 : ans);
}