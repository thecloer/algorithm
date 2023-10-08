#include <iostream>
#include <queue>
using namespace std;

int building[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    building[S] = 1;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty() && !building[G]) {
        int cur = Q.front(); Q.pop();
        for(int nxt : { cur-D, cur+U }) {
            if(nxt < 1 || nxt > F) continue;
            if(building[nxt]) continue;
            building[nxt] = building[cur] + 1;
            Q.push(nxt);
        }
    }
    if(building[G]) cout << building[G] - 1;
    else cout << "use the stairs";
}