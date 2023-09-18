#include <iostream>
#include <string>
#include <list>
using namespace std;
// 600000
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  string s;
  cin >> s;
  int M;
  cin >> M;

  list<char> L;
  for(char c:s) L.push_back(c);
  list<char>::iterator cursor = L.end();

  while(M--){
    char cmd;
    cin >> cmd;
    if(cmd == 'L'){
      if(cursor != L.begin())
        cursor--;
    } else if(cmd == 'D'){
      if(cursor != L.end())
        cursor++;
    } else if(cmd == 'B'){
      if(cursor != L.begin())
        cursor = L.erase(--cursor);
    } else if(cmd == 'P'){
      char c;
      cin >> c;
      L.insert(cursor, c);
    }
  }
  for(auto c:L) cout<<c;
}