#include <iostream>
using namespace std;

void merge(int arr[], int start, int end) {
    int tmp[end-start];
    int mid = (start + end) / 2;
    int left = start, right = mid;
    for(int i = 0; i < end-start; i++) {
        if(right == end) tmp[i] = arr[left++];
        else if(left == mid) tmp[i] = arr[right++];
        else if(arr[left] <= arr[right]) tmp[i] = arr[left++];
        else tmp[i] = arr[right++];
    }
    for(int i=start; i<end; i++) arr[i] = tmp[i-start];
}
void mergeSort(int arr[], int start, int end) {
    if(end - start <= 1) return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid, end);
    merge(arr, start, end);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int &x:arr) cin >> x;
    mergeSort(arr, 0, n);
    for(const int &x:arr) cout << x << '\n';
}