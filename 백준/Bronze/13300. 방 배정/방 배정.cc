#include <iostream>
using namespace std;

int p[7][2];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  int N, K, ans=0;
  cin >> N >> K;
  while(N--){
    int s, g;
    cin >> s >> g;
    p[g][s]++;
  }
  for(int g=1; g<7; g++)
    for(int s=0; s<2; s++)
      ans += (p[g][s] + K-1) / K;
  cout << ans;
}