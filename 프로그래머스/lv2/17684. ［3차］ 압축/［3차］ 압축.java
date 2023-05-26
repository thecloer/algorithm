import java.util.*;
class Solution {
    public int[] solution(String msg) {
        LinkedList<String> dict = new LinkedList();
        LinkedList<Integer> answer = new LinkedList();
        // 1. 초기화
        for(char c='A'; c<='Z'; c++)
            dict.add(c+"");
        
        int wIndex = 0;
        int cIndex = 0;
        while(wIndex < msg.length()) {
            // 2. 현재 입력과 일치하는 가장 긴 문자열 w 찾기
            while(cIndex < msg.length()){
                if(dict.contains(msg.substring(wIndex,cIndex+1))) 
                    cIndex++;
                else break;
            }
            
            String w = msg.substring(wIndex, cIndex);
            // 3. w 인덱스 출력, w+c 등록
            answer.add(dict.indexOf(w) + 1);
            if(cIndex < msg.length())
                dict.add(w + msg.charAt(cIndex));
            
            wIndex = cIndex;
        }
        
        return answer.stream().mapToInt(i->i).toArray();
    }
}