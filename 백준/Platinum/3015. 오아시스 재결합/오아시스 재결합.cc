#include <iostream>
#include <stack>
using namespace std;

struct e {int h, cnt;};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<e> S;
  long long ans = 0;
  while (n--) {
    int h;
    cin >> h;
    int cnt = 1;
    while (!S.empty() && S.top().h <= h) {
      ans += S.top().cnt;
      if (S.top().h == h) cnt += S.top().cnt;
      S.pop();
    }
    if (!S.empty()) ans++;
    S.push({h, cnt});
  }
  cout << ans;
}