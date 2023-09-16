#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int N, first, second;
    first = 0; second = 1;
    cin >> N;
    if(N==0)
        cout << first;
    else {
        while(--N) {
            int tmp = first + second;
            first = second;
            second = tmp;
        }
        cout << second;
    }
    return 0;
}