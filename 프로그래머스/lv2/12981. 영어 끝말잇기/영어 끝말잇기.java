import java.util.*;
class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[2];
        Set<String> wordPool = new HashSet<String>();
        wordPool.add(words[0]);
        int i = 1;
        while(i < words.length){
            if(wordPool.contains(words[i]) || isSequence(words, i)){
                   answer[0] = i % n + 1;
                   answer[1] = i / n + 1;
                   break;
               }
            wordPool.add(words[i]);
            i++;
        }
        
        return answer;
    }
    
    private boolean isSequence(String[] words, int i){
        return words[i-1].charAt(words[i-1].length()-1) != words[i].charAt(0);
    }
}