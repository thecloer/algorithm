#include <iostream>
using namespace std;

typedef long long ll;

ll fibo[91];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    fibo[1]=1;
    int N;
    cin >> N;
    for(int i=2; i<=N; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
    
    cout << fibo[N];
    return 0;
}