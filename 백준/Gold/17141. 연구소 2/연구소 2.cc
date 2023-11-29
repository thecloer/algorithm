#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_VALUE = 101;

struct xy {int x, y;};
int N, M;
int board[50][50];
bool vis[50][50];
vector<xy> available;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isSuccess() {
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(board[i][j] != 1 and not vis[i][j])
                return false;
    return true;
}
int bfs(queue<xy> &Q) {
    int sec = -1;
    while(not Q.empty()) {
        sec++;
        for(int size=Q.size(); size--;) {
            const auto &[x, y] = Q.front(); Q.pop();
            for(int d=4; d--;) {
                int nx = x + dx[d], ny = y + dy[d];
                if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                if(board[nx][ny] == 1 or vis[nx][ny]) continue;
                vis[nx][ny]= true;
                Q.push({nx, ny});
            }
        }
    }
    return sec;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2)
                available.push_back({i, j});
        }
    }
    int mask[available.size()];
    for(int i=0; i<M; i++) mask[i] = 0;
    for(int i=M; i<available.size(); i++) mask[i] = 1;

    int ans = MAX_VALUE;
    do {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                vis[i][j] = false;
        queue<xy> Q;
        for(int i=0; i<N; i++)
        for(int i=0; i<available.size(); i++) {
            if(mask[i]) continue;
            const auto &[x, y] = available[i];
            Q.push({x, y});
            vis[x][y] = true;
        }
        int sec = bfs(Q);
        if(isSuccess()) ans = min(ans, sec);
    } while(next_permutation(mask, mask+available.size()));

    cout << (ans == MAX_VALUE ? -1 : ans);
}