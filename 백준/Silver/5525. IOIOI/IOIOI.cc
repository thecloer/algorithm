#include <iostream>
using namespace std;

int N, M, ans, cnt;
char before, cur;
bool isCounting;

void calc(){
    if(cnt >= N) ans += cnt - N + 1;
    cnt = 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    while(M--) {
        cin >> cur;
        if(isCounting) {
            if(cur == 'I') {
                if(before == 'I') calc();
                else cnt++;
            } else if(before == 'O') {
                calc();
                isCounting = false;
            }
        } else if(cur == 'I') isCounting = true;
        before = cur;
    }
    calc();
    cout << ans;
}