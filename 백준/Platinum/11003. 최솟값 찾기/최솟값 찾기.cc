#include <iostream>
#include <deque>
using namespace std;

int N, L, x;
deque<pair<int, int> > dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> L;
  for(int i=0; i<N; i++){
    cin >> x;
    if(!dq.empty() && dq.front().first <= i - L)
      dq.pop_front();
    while(!dq.empty() && dq.back().second > x)
      dq.pop_back();
    dq.push_back(make_pair(i, x));
    cout << dq.front().second << " ";
  }
  cout << endl;
  return 0;
}