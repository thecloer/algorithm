#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int N; cin >> N;
  int dq[2*N];
  int front=N, back=N;
  while(N--){
    string cmd;
    cin >> cmd;
    if(cmd == "push_front"){
      cin >> dq[--front];
    } else if(cmd == "push_back"){
      cin >> dq[back++];
    } else if(cmd == "size"){
      cout << (back - front) << '\n';
    } else if(cmd == "empty"){
      cout << (back == front ? 1 : 0) << '\n';
    } else if(cmd == "pop_front"){
      cout << (back == front ? -1 : dq[front++]) << '\n';
    } else if(cmd == "pop_back"){
      cout << (back == front ? -1 : dq[--back]) << '\n';
    } else if(cmd == "front"){
      cout << (back == front ? -1 : dq[front]) << '\n';
    } else if(cmd == "back"){
      cout << (back == front ? -1 : dq[back-1]) << '\n';
    }
  }
}