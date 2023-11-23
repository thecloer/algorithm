#include <iostream>
#include <string>
using namespace std;

string arr[20000], tmp[20000];

bool cmp(const string &a, const string &b) {
    if(a.length() != b.length()) return a.length() < b.length();
    for(int i = 0; i < (int)a.length(); i++) {
        if(a[i] == b[i]) continue;
        return a[i] < b[i];
    }
    return true;
}

void mergeSort(int start, int end) {
    if(end - start <= 1) return;
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid, end);
    int left = start, right = mid;
    for(int i = start; i < end; i++) {
        if(left == mid) tmp[i] = arr[right++];
        else if(right == end) tmp[i] = arr[left++];
        else if(cmp(arr[left], arr[right])) tmp[i] = arr[left++];
        else tmp[i] = arr[right++];
    }
    for(int i = start; i < end; i++) arr[i] = tmp[i];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    mergeSort(0, N);
    int size = 1;
    for(int i = 1; i < N; i++) {
        if(arr[i] == arr[i-1]) continue;
        if(size == i) size++;
        else arr[size++] = arr[i];
    }
    for(int i = 0; i < size; i++) cout << arr[i] << '\n';
}