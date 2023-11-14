#include <iostream>
#include <algorithm>
using namespace std;

struct xy {int x, y;};
bool cmp(const xy &a, const xy &b) { 
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
xy points[100000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> points[i].x >> points[i].y;
    sort(points, points + N, cmp);
    for(int i=0; i<N; i++) cout << points[i].x << ' '<< points[i].y << '\n';
}