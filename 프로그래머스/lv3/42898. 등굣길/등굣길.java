import java.util.*;
class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int[][] map = new int[n+1][m+1];
        for(int i=0; i<puddles.length; i++)
            map[puddles[i][1]][puddles[i][0]] = -1;
        for(int y=1; y<=n; y++){
            for(int x=1; x<=m; x++){
                if(x==1 && y==1) {
                    map[y][x]=1;
                    continue;
                };
                if(map[y][x]<0)
                    continue;
                if(map[y-1][x]<0 && map[y][x-1]<0)
                    map[y][x]=-1;
                else if(map[y-1][x]<0)
                    map[y][x]=map[y][x-1];
                else if(map[y][x-1]<0)
                    map[y][x]=map[y-1][x];
                else
                    map[y][x]=(map[y][x-1]+map[y-1][x])%1000000007;
            }
        }
        return map[n][m];
    }
}