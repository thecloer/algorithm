#include <iostream>
#include <queue>
using namespace std;

struct xy {int x, y;};
int dx[] = {1, 0 ,-1, 0};
int dy[] = {0, 1, 0 ,-1};
int N, M, P;
char board[1000][1001];
queue<xy> Qs[10];
int S[10];
int area[10];

bool allEmpty() {
    for(auto Q:Qs)
        if(!Q.empty())
            return false;
    return true;
}
void bfs(int p) {
    queue<xy> &Q = Qs[p];
    int s = S[p];
    while(!Q.empty() && s--) {
        int size = Q.size();
        while(size--) {
            xy cur = Q.front(); Q.pop();
            for(int i=4; i--;) {
                int nx = cur.x + dx[i], ny = cur.y + dy[i];
                if(nx<0 or nx>=N or ny<0 or ny>=M) continue;
                if(board[nx][ny] != '.') continue;
                area[p]++;
                board[nx][ny] = p + '0';
                Q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> P;
    for(int i=1; i<=P; i++) cin >> S[i];
    for(int i=0; i<N; i++) {
        cin >> board[i];
        for(int j=0; j<M; j++) {
            if(isdigit(board[i][j])) {
                int p = board[i][j] - '0';
                Qs[p].push({i, j});
                area[p]++;
            }
        }
    }

    while(not allEmpty())
        for(int i=1; i<=P; i++)
            bfs(i);
    
    for(int i=1; i<=P; i++) 
        cout << area[i] << ' ';
}