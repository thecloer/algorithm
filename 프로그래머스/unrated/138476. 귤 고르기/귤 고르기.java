import java.util.*;
class Solution {
    public int solution(int k, int[] tangerine) {
        Map<Integer,Integer> map = new HashMap();
        for(int key:tangerine)
            map.put(key, map.getOrDefault(key,0)+1);

        Iterator<Integer> iter = map.values().stream().sorted(Collections.reverseOrder()).iterator();
        int sum =0;
        int answer = 0;
        while(iter.hasNext()){
            sum+=iter.next();
            answer++;
            if(sum>=k) break;
        }
        return answer;
    }
}