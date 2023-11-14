#include <iostream>
using namespace std;

struct xy {int x, y;};
bool cmp(const xy &a, const xy &b) { 
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
xy points[100000], tmp[100000];

void mergeSort(int start, int end) {
    if(end - start <= 1) return;
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid, end);
    int left = start, right = mid;
    for(int i = start; i < end; i++) {
        if(left == mid) tmp[i] = points[right++];
        else if(right == end) tmp[i] = points[left++];
        else if(cmp(points[left], points[right])) tmp[i] = points[left++];
        else tmp[i] = points[right++];
    }
    for(int i = start; i < end; i++) points[i] = tmp[i];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> points[i].x >> points[i].y;
    mergeSort(0, N);
    for(int i=0; i<N; i++) cout << points[i].x << ' '<< points[i].y << '\n';
}   