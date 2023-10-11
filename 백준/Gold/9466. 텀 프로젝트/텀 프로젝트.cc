#include <iostream>
using namespace std;

enum Status { NOT_VISITED, VISITED, NOT_CYCLE, CYCLE };
int n; 
int nxt[100001];
Status status[100001];

void run(int x) {
    int cur = x;
    while(true) {
        status[cur] = VISITED;
        cur = nxt[cur];
        if(status[cur] == CYCLE || status[cur] == NOT_CYCLE) {
            cur = x;
            while(status[cur] == VISITED) {
                status[cur] = NOT_CYCLE;
                cur = nxt[cur];
            }
            return;
        }
        if(status[cur] == VISITED) {
            while(status[cur] == VISITED) {
                status[cur] = CYCLE;
                cur = nxt[cur];
            }
            if(cur != x) {
                cur = x;
                while(status[cur] == VISITED) {
                    status[cur] = NOT_CYCLE;
                    cur = nxt[cur];
                }
            }
            return;
        }
        
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> nxt[i];
            status[i] = NOT_VISITED;
        }

        for(int i=1; i<=n; i++)
            if(status[i] == NOT_VISITED)
                run(i);
        
        int ans = 0;
        for(int i=1; i<=n; i++)
            if(status[i] == NOT_CYCLE) ans++;
        cout << ans << '\n';
    }
}