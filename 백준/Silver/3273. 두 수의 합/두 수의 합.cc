#include <iostream>
#include <vector>
using namespace std;

int arr[1000001];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int n, x, ans=0;
  cin >> n;
  int input[n];
  for(int i=0; i<n; i++) {
    cin >> input[i];
    arr[input[i]] = 1;
  }
  cin >> x;
  for(int i=0, half=(x+1)/2; i<n; i++){
    if(input[i] < half){
      int y = x - input[i];
      if(y < 1000001 && arr[y])
        ans++;
    }
  }
  cout << ans;

  return 0;
}