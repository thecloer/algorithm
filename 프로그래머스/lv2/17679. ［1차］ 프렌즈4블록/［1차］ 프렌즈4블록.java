class Solution {
    public int solution(int m, int n, String[] board) {
        char[][] map = new char[n][m];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                map[j][i] = board[i].charAt(j);
        
        int answer = 0;        
        int point = 0;
        do {
            point = 0;
            boolean[][] cMap = new boolean[n][m];
            for(int i=0; i<n-1; i++){
                for(int j=0; j<m-1; j++){
                    if(map[i][j]=='0')
                        continue;
                    if(map[i][j] == map[i][j+1] && 
                       map[i][j] == map[i+1][j] &&
                       map[i+1][j] == map[i+1][j+1]){
                        for(int k=0; k<4; k++){
                            if(!cMap[i+k/2][j+k%2]){
                                cMap[i+k/2][j+k%2] = true;
                                point++;
                            }
                        }
                    }
                }
            }
            for(int i=0; i<n; i++){
                for(int j=m-1, k=m-1; j>=0;){
                    if(k < 0)
                        map[i][j--] = '0';
                    else if(!cMap[i][k]){
                        map[i][j--] = map[i][k--];
                    } else
                        k--;
                }
            }
            answer+=point;
            
        } while(point > 0);
        
        return answer;
    }
}