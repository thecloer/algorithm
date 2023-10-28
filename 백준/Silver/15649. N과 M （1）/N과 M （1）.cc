#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool used[9];
int result[8];

void permutation(int size) {
    if(size == M) {
        for(int i=0; i<size; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    for(int x=1; x<=N; x++) {
        if(used[x]) continue;
        result[size] = x;
        used[x] = true;
        permutation(size + 1);
        used[x] = false;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    permutation(0);
}