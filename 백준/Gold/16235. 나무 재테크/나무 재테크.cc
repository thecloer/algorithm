#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int land[11][11];
int S2D2[11][11];
vector<int> trees[11][11];
vector<int> alive[11][11];
vector<int> dead[11][11];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring() {
    for(int x=1; x<=N; x++) {
        for(int y=1; y<=N; y++) {
            sort(trees[x][y].begin(), trees[x][y].end());
            for(int age:trees[x][y]) {
                if(age <= land[x][y]) {
                    land[x][y] -= age;
                    alive[x][y].push_back(age + 1);
                }
                else dead[x][y].push_back(age);
            }
            trees[x][y].clear();
        }
    }
}
void summer() {
    for(int x=1; x<=N; x++) {
        for(int y=1; y<=N; y++) {
            for(int age:dead[x][y])
                land[x][y] += age / 2;
            dead[x][y].clear();
        }
    }
}
void fall() {
    for(int x=1; x<=N; x++) {
        for(int y=1; y<=N; y++) {
            for(int age:alive[x][y]) {
                trees[x][y].push_back(age);
                if(age % 5) continue;
                for(int d=8; d--;) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if(nx<1||nx>N||ny<1||ny>N) continue;
                    trees[nx][ny].push_back(1);
                }
            }
            alive[x][y].clear();
        }
    }
}
void winter() {
    for(int x=1; x<=N; x++)
        for(int y=1; y<=N; y++)
            land[x][y] += S2D2[x][y];
}
int countTrees() {
    int cnt = 0;
    for(int x=1; x<=N; x++)
        for(int y=1; y<=N; y++)
            cnt += trees[x][y].size();
    return cnt;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int x=1; x<=N; x++) {
        for(int y=1; y<=N; y++) {
            cin >> S2D2[x][y];
            land[x][y] = 5;
        }
    }
    while(M--) {
        int x, y, z; cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }
    while(K--) {
        spring();
        summer();
        fall();
        winter();
    }
    cout << countTrees();
}