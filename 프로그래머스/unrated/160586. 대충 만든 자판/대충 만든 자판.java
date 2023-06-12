import java.util.*;
class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        Map<Character, Integer> map = new HashMap();
        for(String key:keymap){
            for(int i=0; i<key.length(); i++){
                char c = key.charAt(i);
                map.put(c, Math.min(map.getOrDefault(c,i+1), i+1));
            }
        }
        int[] answer = new int[targets.length];
        for(int i=0; i<targets.length; i++){
            for(char c:targets[i].toCharArray()){
                int count = map.getOrDefault(c, -1);
                if(count<0){
                    answer[i] = -1;
                    break;
                }
                answer[i] += count;
            }
        }
        return answer;
    }
}