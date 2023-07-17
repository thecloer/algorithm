import java.util.*;
class Solution {
    public int solution(int[][] lines) {
        int min=101, max=-101;
        for(int[] line:lines){
            min=Math.min(min,line[0]);
            max=Math.max(max,line[1]);
        }
        
        int[] l = new int[max-min];
        for(int[] line:lines)
            for(int n=line[0]; n<line[1]; n++)
                l[n-min]++;
        int answer = 0;
        for(int n:l)
            if(n>1)
                answer++;
        return answer;
    }
}