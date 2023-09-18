#include <iostream>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  int ans = 0;
  int a[26] = {};
  string s1,s2;
  cin >> s1 >> s2;

  for(auto c:s1) a[c-'a']++;
  for(auto c:s2) a[c-'a']--;
  for(int i:a)
    ans += abs(i);
  cout << ans;
}