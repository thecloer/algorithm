import java.util.*;
class Solution {
    public String solution(String[] survey, int[] choices) {
        HashMap<String, Integer> points = new HashMap<>();
        points.put("RT",0);
        points.put("CF",0);
        points.put("JM",0);
        points.put("AN",0);
        
        for(int i=0; i<survey.length; i++){
            String key = survey[i];
            boolean isReverse = !points.containsKey(key);
            if(isReverse) key = "" + key.charAt(1) + key.charAt(0);
            points.put(key, points.get(key) + (isReverse? -1:1) * (choices[i] - 4));
        }
        
        String answer = "";
        Iterator<String> keys = points.keySet().iterator();
        while(keys.hasNext()){
            String key = keys.next();
            int point = points.get(key);
            
            if(point < 0) answer += key.charAt(0);
            else if(point > 0) answer += key.charAt(1);
            else answer += (char)Math.min(key.charAt(0), key.charAt(1));
        }
        
        return answer;
    }
}