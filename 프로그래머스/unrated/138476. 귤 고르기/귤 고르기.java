import java.util.*;
class Solution {
    public int solution(int k, int[] tangerine) {
        Map<Integer,Integer> map = new HashMap();
        for(int key:tangerine)
            map.put(key, map.getOrDefault(key,0)+1);
        
        Integer[] counts = map.values().stream().sorted(Collections.reverseOrder()).toArray(Integer[]::new);
        int sum =0;
        int answer = 0;
        for(int count:counts){
            sum+=count;
            answer++;
            if(sum>=k) break;
        }
        return answer;
    }
}