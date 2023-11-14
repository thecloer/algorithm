#include <iostream>
using namespace std;

int arr[1000001], tmp[1000001];

void mergeSort(int start, int end) {
    if(end - start <= 1) return;
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid, end);
    int left = start, right = mid;
    for(int i=start; i<end; i++) {
        if(left == mid) tmp[i] = arr[right++];
        else if(right == end) tmp[i] = arr[left++];
        else if(arr[left] >= arr[right]) tmp[i] = arr[left++];
        else tmp[i] = arr[right++];
    }
    for(int i=start; i<end; i++) arr[i] = tmp[i];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    mergeSort(0, N);
    for(int i=0; i<N; i++) cout << arr[i] << '\n';
}