#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

bool cmp(ll a, ll b) {return a > b;}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; ll M;
    cin >> N >> M;

    ll trees[N + 1];
    for(int i=0; i<N; i++) cin >> trees[i];
    sort(trees, trees + N, cmp);
    trees[N] = 0;

    ll height = 0, bring = 0;
    for(int width = 1; width <= N; width++) {
        bring += width * (trees[width-1] - trees[width]);
        if(bring >= M) {
            height = trees[width] + (bring - M) / width;
            break;
        }
    }
    cout << height;
}