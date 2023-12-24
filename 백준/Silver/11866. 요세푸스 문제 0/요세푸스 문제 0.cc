#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, K; cin >> N >> K;
  queue<int> Q;
  for(int i=1; i<=N; i++) Q.push(i);
  cout << '<';
  for(int cnt=0; not Q.empty();) {

    int x = Q.front(); Q.pop();
    if(++cnt == K) {
      cnt = 0;
      cout << x << (Q.empty() ? ">" : ", ");
    }
    else Q.push(x);
  }
}