#include <vector>
#include <queue>
using namespace std;
bool matrix[20001][20001];
bool vis[20001];

int solution(int n, vector<vector<int>> edge) {
    for(auto &e:edge) {
        matrix[e[0]][e[1]] = 1;
        matrix[e[1]][e[0]] = 1;
    }
    queue<int> Q;
    Q.push(1);
    vis[1] =1;
    int size;
    while(!Q.empty()) {
        size = Q.size();
        for(int i=0; i<size; i++) {
            int x = Q.front(); Q.pop();
            for(int nx=1; nx<=n; nx++) {
                if(matrix[x][nx] && !vis[nx]) {
                    vis[nx] = 1;
                    Q.push(nx);
                }
            }
        }
    }
    return size;
}