#include <iostream>
using namespace std;

int N, L;
int board[100][100];
int road[100];

bool canPass() {
    int idx = 0, len = 1;
    while(idx < N-1) {
        int dh = road[idx+1] - road[idx];
        if(dh == 0) {
            idx++;
            len++;
        }
        else if(dh == 1) {
            if(len < L) return false;
            idx++;
            len = 1;
        }
        else if(dh == -1) {
            if(idx + L >= N) return false;
            for(int i=idx+1; i<idx+L; i++)
                if(road[i] != road[i+1])
                    return false;
            idx += L;
            len = 0;
        }
        else return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];

    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            road[j] = board[i][j];
        if(canPass()) ans++;
    }
    for(int j=0; j<N; j++) {
        for(int i=0; i<N; i++) 
            road[i] = board[i][j];
        if(canPass()) ans++;
    }
    cout << ans;
}