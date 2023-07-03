class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int[][] map = new int[m+1][n+1];
        for(int[] p:puddles)
            map[p[0]][p[1]] = -1;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(i==1 && j==1){
                    map[i][j]=1;
                    continue;
                }
                if(map[i][j]==-1){
                    map[i][j]=0;
                    continue;
                }
                map[i][j] = (map[i-1][j] + map[i][j-1])%1000000007;
            }
        }
        return map[m][n];
    }
}