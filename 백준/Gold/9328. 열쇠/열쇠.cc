#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct xy {int x, y;};
char board[102][102];
int vis[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int mark; cin >> mark;
    while(mark) {
        int h, w, ans = 0;
        bool open[26] = {};
        vector<xy> locked[26];
        queue<xy> Q;

        cin >> h >> w;
        for(int i=1; i<=h; i++) cin >> (board[i] + 1);
        for(int i:{0, h+1}) 
            for(int j=0; j<w+2; j++)
                board[i][j] = '\0';
        for(int i=1; i<h; i++) 
            for(int j:{0, w+1})
                board[i][j] = '\0';
        string keystr; cin >> keystr;
        if(keystr != "0")
            for(char k:keystr) open[k - 'a'] = true;

        Q.push({0, 0});
        vis[0][0] = mark;
        while(!Q.empty()) {
            xy cur = Q.front(); Q.pop();
            for(int dir=4; dir--;) {
                int nx = cur.x + dx[dir], ny = cur.y + dy[dir];
                if(nx<0 || nx>(h+1) || ny<0 || ny>(w+1)) continue;
                if(board[nx][ny] == '*' || vis[nx][ny] == mark) continue;
                vis[nx][ny] = mark;
                if(board[nx][ny] >= 'A' && board[nx][ny] <= 'Z') {
                    int k = board[nx][ny] - 'A';
                    if(!open[k]) {
                        locked[k].push_back({nx, ny});
                        continue;
                    }
                }
                else if(board[nx][ny] >= 'a' && board[nx][ny] <= 'z') {
                    int k = board[nx][ny] - 'a';
                    open[k] = true;
                    while(!locked[k].empty()) {
                        Q.push(locked[k].back());
                        locked[k].pop_back();
                    }
                }
                else if(board[nx][ny] == '$') ans++;
                Q.push({nx, ny});
            }
        }
        cout << ans << '\n';
        mark--;
    }
}