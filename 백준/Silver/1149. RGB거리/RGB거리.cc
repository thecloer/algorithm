#include <iostream>
using namespace std;

inline int min(int x, int y) {return x < y ? x : y;}

int n, R, G, B, r, g, b;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    while(n--){
        cin >> r >> g >> b;
        r += min(G, B);
        g += min(R, B);
        b += min(R, G);
        
        R = r; G = g; B = b;
    }
    cout << min(min(R, G), B);
    return 0;
}