import java.util.*;
class Solution {
    public int[][] solution(int n) {
        int[][] answer = new int[n][n];
        for(int e=n-1, x=0, y=0, k=1; e>=0; e-=2){
            if(e==0)
                answer[x][y] = k;
            for(int i=0; i<4; i++){
                for(int j=0; j<e; j++){
                    answer[x][y] = k++;
                    if(i==0)
                        y++;
                    else if(i==1)
                        x++;
                    else if(i==2)
                        y--;
                    else if(j==e-1)
                        y++;
                    else
                        x--;
                }
            }
        }
        for(int[] a:answer)
            System.out.println(Arrays.toString(a));
        return answer;
    }
}