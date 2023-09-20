#include <iostream>
#include <stack>
using namespace std;

struct building {
  int idx, height;
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int N;
  cin >> N;
  stack<building> S;
  for(int i=0, x; i<N; i++){
    cin >> x;
    while(!S.empty() && S.top().height <= x) S.pop();

    if(S.empty()) cout << "0 ";
    else cout << S.top().idx << ' ';
    
    building b;
    b.idx = i+1;
    b.height = x;
    S.push(b);
  }
}