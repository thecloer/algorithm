#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;

unordered_map<ll, ll> memo = {{0, 0}, {1, 1}};

ll fibo(ll n) {
    if(memo.find(n) != memo.end()) return memo[n];
    if(n & 1) memo[n] = fibo(n/2) * fibo(n/2) + fibo(n/2+1) * fibo(n/2+1);
    else memo[n] = fibo(n/2) * (fibo(n/2) + 2*fibo(n/2-1));
    memo[n] %= 1000000007;
    return memo[n];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    cout << fibo(n);
}
