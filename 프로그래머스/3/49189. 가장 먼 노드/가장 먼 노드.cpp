#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

bool used[20001];

int solution(int n, vector<vector<int>> edge) {
    unordered_map<int, vector<int>> adj;
    for(auto &e:edge) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    queue<int> Q;
    used[1] = 1;
    Q.push(1);
    int size;
    while(!Q.empty()) {
        size = Q.size();
        for(int i=0; i<size; i++) {
            int x = Q.front(); Q.pop();
            for(int nx:adj[x]) {
                if(used[nx]) continue;
                used[nx] = 1;
                Q.push(nx);
            }
        }
    }
    return size;
}