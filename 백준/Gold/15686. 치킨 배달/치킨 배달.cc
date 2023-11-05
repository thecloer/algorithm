#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int abs(int a) { return a < 0 ? -a : a; };
inline int min(int a, int b) { return a < b ? a : b; };

struct xy {int x, y;};
int N, M;
int board[50][50];
vector<xy> house, chicken;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) 
                house.push_back({i, j});
            else if(board[i][j] == 2) 
                chicken.push_back({i, j});
        } 
    }
    
    int ans = 250000;
    vector<int> mask(chicken.size(), 1);
    for(int i=0; i<M; i++) mask[i] = 0;
    do {
        vector<xy> selected;
        for(int i=0; i<mask.size(); i++)
            if(mask[i] == 0) selected.push_back(chicken[i]);
        
        int cityDist = 0;
        for(const auto &[x1, y1] : house) {
            int houseDist = 2501;
            for(const auto &[x2, y2]: selected)
                houseDist = min(houseDist, abs(x1-x2) + abs(y1-y2));
            cityDist += houseDist;
        }
        ans = min(ans, cityDist);
    } while(next_permutation(mask.begin(), mask.end()));
    cout << ans;
}