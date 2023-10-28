#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool used[9];
vector<int> selected;

void permutation() {
    if(selected.size() == M) {
        for(int x:selected) cout << x << ' ';
        cout << '\n';
        return;
    }
    for(int i=1; i<=N; i++) {
        if(used[i]) continue;
        used[i] = true;
        selected.push_back(i);
        permutation();
        selected.pop_back();
        used[i] = false;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    permutation();
}