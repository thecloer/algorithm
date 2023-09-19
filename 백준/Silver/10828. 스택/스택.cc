#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int N;
  cin >> N;

  int stack[N];
  int end = 0;
  while(N--) {
    string cmd;
    cin >> cmd;
    if(cmd == "push") {
      int x;
      cin >> x;
      stack[end++] = x;
    } else if(cmd == "pop") {
      if(end == 0) cout << -1;
      else cout << stack[--end];
      cout << '\n';
    } else if(cmd == "size") {
      cout << end << '\n';
    } else if(cmd == "empty") {
      cout << (end == 0 ? 1 : 0) << '\n';
    } else if(cmd == "top") {
      if(end == 0) cout << -1;
      else cout << stack[end-1];
      cout << '\n';
    }
  }
}