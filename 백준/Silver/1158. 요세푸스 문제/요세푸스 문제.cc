#include <iostream>
#include <list>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  int N,K;
  cin >> N >> K;

  list<int> L;
  for(int i=1; i<=N; i++) L.push_back(i);

  cout << '<';
  auto p = L.begin();
  int i = 1;
  while(!L.empty()){
    if(i%K==0) {
      cout << *p;
      p = L.erase(p);
      cout << (L.empty() ? ">" : ", ");
    } else p++;
    if(p == L.end()) p = L.begin();
    i++;
  }
}