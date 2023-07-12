import java.util.*;
class Solution {
    public int solution(int[][] routes) {
        Arrays.sort(routes, (r1, r2)->r1[1]-r2[1]);
        int answer = 1;
        int last = routes[0][1];
        for(int i=1; i<routes.length; i++){
            if(routes[i][0]>last){
                last = routes[i][1];
                answer++;
            }
        }
        return answer;
    }
}