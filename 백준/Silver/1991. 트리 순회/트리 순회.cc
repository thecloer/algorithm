#include <iostream>
using namespace std;

struct node {char cur; int left, right;};
node nodes[26];

void preorder_traversal(int cur) {
    cout << nodes[cur].cur;
    if(nodes[cur].left) preorder_traversal(nodes[cur].left);
    if(nodes[cur].right) preorder_traversal(nodes[cur].right);
}
void inorder_traversal(int cur) {
    if(nodes[cur].left) inorder_traversal(nodes[cur].left);
    cout << nodes[cur].cur;
    if(nodes[cur].right) inorder_traversal(nodes[cur].right);
}
void postorder_traversal(int cur) {
    if(nodes[cur].left) postorder_traversal(nodes[cur].left);
    if(nodes[cur].right) postorder_traversal(nodes[cur].right);
    cout << nodes[cur].cur;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    while(N--) {
        char cur, left, right;
        cin >> cur >> left >> right;
        nodes[cur - 'A'].cur = cur;
        if(left != '.') nodes[cur - 'A'].left = left - 'A';
        if(right != '.') nodes[cur - 'A'].right = right - 'A';
    }
    preorder_traversal(0);
    cout << '\n';
    inorder_traversal(0);
    cout << '\n';
    postorder_traversal(0);
}