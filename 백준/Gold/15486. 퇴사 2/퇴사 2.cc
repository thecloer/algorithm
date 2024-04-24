#include <iostream>
using namespace std;

int N;
int T[1500000], P[1500000], dp[1500000];

inline int max(int a, int b) {return a > b ? a : b;}
int doOrNot(int day) {
    if(day >= N) return 0;
    if(dp[day]) return dp[day];
    if(day + T[day] > N) return dp[day] = doOrNot(day + 1);
    return dp[day] = max(P[day] + doOrNot(day + T[day]), doOrNot(day + 1));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> T[i] >> P[i];
    cout << doOrNot(0);
}