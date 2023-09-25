#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  int N; cin >> N;
  int q[N];
  int front=0, back=0;
  while(N--){
    string cmd; cin >> cmd;
    if(cmd == "push") {
      int x; cin >> x;
      q[back++] = x;
    } else if (cmd == "pop"){
      if(front == back) cout << -1;
      else cout << q[front++];
      cout << '\n';
    } else if (cmd == "size"){
      cout << back - front << '\n';
    } else if (cmd == "empty"){
      cout << (back - front == 0 ? 1 : 0) << '\n';
    } else if (cmd == "front"){
      if(front == back) cout << -1;
      else cout << q[front];
      cout << '\n';
    } else if (cmd == "back"){
      if(front == back) cout << -1;
      else cout << q[back-1];
      cout << '\n';
    }
  }
}