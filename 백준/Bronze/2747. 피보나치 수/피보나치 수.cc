#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int N, first=0, second=1, tmp;
    cin >> N;
    while(--N) {
        tmp = first;
        first = second;
        second += tmp;
    }
    cout << second;
    return 0;
}