#include <iostream>
using namespace std;

const int MAX = 5001;
int nxt[MAX];
int pre[MAX];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int N, K, len;
  cin >> N >> K;

  len = N;
  for(int i=1; i<=N; i++) {
    nxt[i] = (i==N) ? 1 : i+1;
    pre[i] = (i==1) ? N : i-1;
  }

  cout << '<';
  for(int i = 1, cur = 1; len > 0; cur = nxt[cur]){
    if(i == K) {
      i = 1;
      len--;
      nxt[pre[cur]] = nxt[cur];
      pre[nxt[cur]] = pre[cur];
      cout << cur << (len == 0 ? ">" : ", ");
    } else ++i;
  }
}