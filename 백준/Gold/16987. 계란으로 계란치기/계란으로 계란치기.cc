#include <iostream>
using namespace std;

int N, ans;
int health[8], attack[8];

void backTracking(int picked) {
    if(picked == N) {
        int broken = 0;
        for(int i=0; i<N; i++)
            if(health[i] <= 0) broken++;
        if(broken > ans) ans = broken;
        return;
    }
    if(health[picked] <= 0) return backTracking(picked + 1);
    
    bool hasCrashed = false;
    for(int selected = 0; selected < N; selected++) {
        if(selected == picked) continue;
        if(health[selected] <= 0) continue;
        health[selected] -= attack[picked];
        health[picked] -= attack[selected];
        backTracking(picked + 1);
        health[selected] += attack[picked];
        health[picked] += attack[selected];
        if(not hasCrashed) hasCrashed = true;
    }
    if(not hasCrashed) backTracking(picked + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) 
        cin >> health[i] >> attack[i];
    backTracking(0);
    cout << ans;
}