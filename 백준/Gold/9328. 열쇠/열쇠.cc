#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct xy {int x, y;};
int mark, h, w;
string keys;
char board[100][100];
int vis[100][100];
vector<xy> doors[26];
bool open[26];
queue<xy> Q;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isDoor(char x) {return x >= 'A' and x <= 'Z';}
bool isKey(char x) {return x >= 'a' and x <= 'z';}
bool OOB(int x, int y) {return x<0 or x>=h or y<0 or y>=w;}
bool blocked(int x, int y) {
    if(OOB(x, y)) return true;
    if(board[x][y] == '*') return true;
    if(vis[x][y] == mark) return true;
    if(isDoor(board[x][y]) and not open[board[x][y] - 'A']) return true;
    return false;
}
void openDoor(char key) {
    open[key - 'a'] = true;
    auto &door = doors[key - 'a'];
    while(not door.empty()) {
        auto [x, y] = door.back(); door.pop_back();
        for(int dir=4; dir--;) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny] == mark) {
                Q.push({x, y});
                break;
            }
        }
    }
}

void bfs(int &ans, int X, int Y) {
    Q.push({X, Y});
    vis[X][Y] = mark;
    while(not Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        if(board[x][y] == '$') ans++;
        else if(isKey(board[x][y]) and not open[board[x][y] - 'a'])
            openDoor(board[x][y]);
        
        for(int dir=4; dir--;) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if(blocked(nx, ny)) continue;
            vis[nx][ny] = mark;
            Q.push({nx ,ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> mark;
    while(mark) {
        for(int i=0; i<26; i++) {
            doors[i].clear();
            open[i] = false;
        }
        cin >> h >> w;
        for(int i=0; i<h; i++) {
            cin >> board[i];
            for(int j=0; j<w; j++)
                if(isDoor(board[i][j]))
                    doors[board[i][j] - 'A'].push_back({i, j});
        }
        cin >> keys;
        if(keys != "0")
            for(char key:keys)
                openDoor(key);
            
        int ans = 0, x = 0, y = 0, n = 2*(w+h)-4, dir = 0;
        while(n--) {
            if(not blocked(x, y))
                bfs(ans, x, y);

            int nx = x + dx[dir], ny = y + dy[dir];
            if(OOB(nx, 0)) y += dy[++dir];
            else if(OOB(0, ny)) x += dx[++dir];
            else {x = nx; y = ny;}
        }
        cout << ans << '\n';
        mark--;
    }
}