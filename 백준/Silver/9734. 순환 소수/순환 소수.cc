#include <iostream>
#include <string>
using namespace std;

inline void stack(int &n, int a) { 
    n = 10*n + a; 
}
int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        string s; cin >> s;
        if(cin.eof()) break;

        int i=-1, n=0, u=0, d=0, nines=0, zeros=0;
        while(s[++i] != '.') {
            stack(n, s[i] - '0');
            stack(u, s[i] - '0');
        }
        while(s[++i] != '(') {
            stack(n, s[i] - '0');
            stack(u, s[i] - '0');
            zeros++;
        }
        while(s[++i] != ')') {
            stack(n, s[i] - '0');
            nines++;
        }
        u = n-u;
        while(nines--) stack(d, 9);
        while(zeros--) stack(d, 0);

        int g = gcd(u,d);
        u /= g; d /= g;
        cout << s << " = " << u << " / " << d << '\n';
    }
}