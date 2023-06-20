import java.util.*;
class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        int rest = -n;
        for(int w:works)
            rest+=w;
        if(rest<=0) 
            return answer;
        
        Arrays.sort(works);
        int width = works.length + 1;
        for(int i=0; i<works.length; i++){
            if(works[i]>rest/--width)
                break;
            rest-=works[i];
            answer += Math.pow((long)works[i],2);
        }
        answer += Math.pow((long)rest/width+1,2) * (rest%width)
                + Math.pow((long)rest/width,2) * (width - rest%width);
        return answer;
    }
}