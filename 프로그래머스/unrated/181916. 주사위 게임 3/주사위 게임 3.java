import java.util.*;
class Solution {
    public int solution(int a, int b, int c, int d) {
        int[] input = new int[] {a,b,c,d};
        Map<Integer, Integer> map = new HashMap();
        for(int i:input)
            map.put(i, map.getOrDefault(i,0)+1);
        
        int answer=0;
        Set<Integer> keys = map.keySet();
        if(keys.size()==1) {
            answer = 1111*a;
        } else if(keys.size()==4) {
            answer=6;
            for(int n:input)
                answer = Math.min(answer, n);
        } else if(keys.size()==3) {
            for(int k:keys)
                if(map.get(k)==1)
                    answer = answer==0? k : answer*k;
        } else {
            boolean isAbs = false;
            for(int k:keys) {
                if(map.get(k)==2){
                    answer = -answer + (int)Math.pow(k,2);
                    isAbs = true;
                } else 
                    answer += map.get(k)==1? k : 10*k;
            }
            answer = isAbs? Math.abs(answer) : (int)Math.pow(answer,2);
        }
        return answer;
    }
}