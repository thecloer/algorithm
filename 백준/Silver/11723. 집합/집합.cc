#include <iostream>
#include <string>
using namespace std;

const int FULL_SET = (1 << 21) - 2;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int M, s = 0, n; 
    string cmd;

    cin >> M;
    while(M--) {
        cin >> cmd;
        if(cmd == "all") s = FULL_SET;
        else if(cmd == "empty") s = 0;
        else {
            cin >> n;
            if(cmd == "add") s |= 1 << n;
            else if(cmd == "remove") s &= ~(1 << n);
            else if(cmd == "check") cout << ((s & 1 << n) != 0) << '\n';
            else if(cmd == "toggle") s ^= 1 << n;
        }
    }
}