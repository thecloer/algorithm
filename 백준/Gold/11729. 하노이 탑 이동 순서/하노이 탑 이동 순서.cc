#include <iostream>
#include <vector>
using namespace std;

struct e {int from, to;};
vector<e> v;

void move(int n, int from, int to) {
    if(n == 1) {
        v.push_back({from, to});
        return;
    }
    int tmp = 6-from-to;
    move(n-1, from, tmp);
    v.push_back({from, to});
    move(n-1, tmp, to);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    move(N, 1, 3);
    cout << v.size() << '\n';
    for(const auto &x:v) 
        cout << x.from << ' ' << x.to << '\n';
}