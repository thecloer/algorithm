#include <iostream>
#include <stack>
using namespace std;
#define idx first
#define height second

int N;
stack<pair<int,int>> S;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin >> N;
  S.push({0, 100000001});
  for (int i = 1; i <= N; i++) {
    int height;
    cin >> height;
    while (S.top().height < height)
      S.pop();    
    cout << S.top().idx << " ";
    S.push({i, height});
  }
}