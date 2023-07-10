import java.util.*;
class Solution {
    public int solution(String[] babbling) {
        Map<Character, String> map = new HashMap(){{
            put('y', "ye");
            put('m', "ma");
            put('a', "aya");
            put('w', "woo");
        }};
        int answer = 0;
        babblingLoop: for(String b:babbling){
            int cursor = 0;
            String before = "";
            while(cursor < b.length()){
                String w = map.getOrDefault(b.charAt(cursor), null);
                if(w == null || w.equals(before) || !b.startsWith(w, cursor)) 
                    continue babblingLoop;
                before = w;
                cursor += w.length();
            }
            System.out.println(b);
            System.out.println(cursor);
            if(cursor == b.length())
                answer++;
        }
        return answer;
    }
}