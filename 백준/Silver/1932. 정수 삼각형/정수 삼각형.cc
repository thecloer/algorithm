#include <iostream>
using namespace std;

int tri[501][501];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> tri[i][j];
            tri[i][j] += max(tri[i-1][j], tri[i-1][j-1]);
        }
    }
    int ans = tri[n][1];
    for(int i=2; i<=n; i++)
        if(ans < tri[n][i])
            ans = tri[n][i];
    cout << ans;
}