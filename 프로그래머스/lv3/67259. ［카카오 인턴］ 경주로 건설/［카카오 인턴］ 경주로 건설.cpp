#include <vector>
#include <queue>
using namespace std;

struct p { int x, y, d, cost; };
bool comp(p p1, p p2) { return p1.cost > p2.cost; }
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int cost[25][25][4];

int solution(vector<vector<int>> board) {
    int dest = board.size()-1;
    priority_queue<p,vector<p>,decltype(&comp)> pq(comp);
    pq.push({0, 0, -1, -500});
    board[0][0] = 1;
    while(!pq.empty()) {
        p cur = pq.top(); pq.pop();
        for(int d=4; d--;) {
            if(cur.d != d && (cur.d%2 == d%2)) continue;
            int nx = cur.x + dx[d], ny = cur.y + dy[d];
            if(nx<0 || nx>dest || ny<0 || ny>dest) continue;
            if(board[nx][ny] == 1) continue;
            int ncost = cur.cost + 100;
            if(cur.d != d) ncost += 500;
            if(cost[nx][ny][d] == 0 || cost[nx][ny][d] > ncost) {
                cost[nx][ny][d] = ncost;
                pq.push({nx, ny, d, ncost});
            }
        }
    }
    
    int ans = ~(1<<31);
    for(int c:cost[dest][dest])
        if(c > 0 && c < ans) ans = c;
    
    return ans;
}