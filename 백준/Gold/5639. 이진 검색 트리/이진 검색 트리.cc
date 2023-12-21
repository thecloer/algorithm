#include <iostream>
using namespace std;
const int ROOT = 1;

int V[10001], L[10001], R[10001], len;

inline int makeNode(int val) {
    V[++len] = val;
    return len;
}
void push(int node, int val) {
    if(V[ROOT] == 0) {
        V[++len] = val;
        return;
    }
    if(val < V[node]) {
        if(L[node]) push(L[node], val);
        else L[node] = makeNode(val);
    }
    else {
        if(R[node]) push(R[node], val);
        else R[node] = makeNode(val);
    }
}

void printTree(int node) {
    if(node < ROOT or node > len) return;
    printTree(L[node]);
    printTree(R[node]);
    cout << V[node] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int x;
    while(cin >> x) push(ROOT, x);
    printTree(ROOT);
}