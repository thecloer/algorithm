#include <iostream>
#include <vector>
using namespace std;

int parent[100001];

void connect(int a, int b) {
    if(parent[a] && parent[b]) {
        if(parent[b] != a) {
            connect(b, parent[b]);
            parent[b] = a;
        }
        return;
    }
    if(!parent[b]) parent[b] = a;
    if(!parent[a]) parent[a] = b;
}
// void connect(int a, int b) {
//     if(!parent[a]) {
//         parent[a] = b;
//         if(!parent[b]) parent[b] = a;
//     }
//     else if(!parent[b]) parent[b] = a;
//     else if(parent[b] != a) {
//         connect(b, parent[b]);
//         parent[b] = a;
//     }
// }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    parent[1] = 1;
    vector<int> ancestor;
    for(int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        if(a == 1) ancestor.push_back(b);
        else if(b == 1) ancestor.push_back(a);
        else connect(a, b);
    }

    for(int x:ancestor) connect(1, x);

    for(int i=2; i<=N; i++)
        cout << parent[i] << '\n';
}