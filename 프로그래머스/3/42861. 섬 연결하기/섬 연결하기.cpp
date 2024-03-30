#include <vector>
#include <algorithm>

using namespace std;

inline int fnd(int x, vector<int> &root) {
    return root[x] == -1 ? x : (root[x] = fnd(root[x], root));
}
inline void uni(int x, int y, vector<int> &root) {
    root[fnd(x, root)] = fnd(y, root);
}

int solution(int n, vector<vector<int>> costs) {
    vector<int> root(n, -1);
    sort(costs.begin(), costs.end(), 
         [](const vector<int> &x, const vector<int> &y) {
             return x[2] < y[2];
         }
    );
    
    int ans = 0;
    for(auto const &edge:costs) {
        int x = edge[0], y = edge[1];
        if(fnd(x, root) == fnd(y, root)) continue;
        uni(x, y, root);
        ans += edge[2];
    }
    return ans;
}