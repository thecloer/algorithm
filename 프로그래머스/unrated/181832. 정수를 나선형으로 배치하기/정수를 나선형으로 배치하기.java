class Solution {
    public int[][] solution(int n) {
        int[][] answer = new int[n][n];
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        int x=0, y=0, num=1, d=0;
        while(num<=n*n){
            answer[x][y] = num++;
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx<0 || nx>=n || ny<0 || ny>=n || answer[nx][ny]!=0){
                d = ++d%4;
                nx = x + dx[d];
                ny = y + dy[d];
            }
            x = nx;
            y = ny;
        }
        return answer;
    }
}