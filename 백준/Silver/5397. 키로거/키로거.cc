#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  int T;
  cin>>T;
  while(T--){
    list<char> L;
    auto cursor = L.end();
    string s;
    cin >> s;
    for(char c:s){
      if(c=='-') {
        if(cursor != L.begin())
          cursor = L.erase(--cursor);
      } else if(c == '<') {
        if(cursor != L.begin())
          cursor--;
      } else if(c == '>') {
        if(cursor != L.end())
          cursor++;
      } else 
        L.insert(cursor, c);
    }
    for(char c:L) cout << c;
    cout << endl;
  }
}