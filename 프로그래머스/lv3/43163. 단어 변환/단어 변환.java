import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        boolean[] used = new boolean[words.length];
        Queue<Word> q = new LinkedList();
        q.add(new Word(begin, 0));
        while(!q.isEmpty()){
            Word w = q.poll();
            for(int i=0; i<words.length; i++){
                if(!used[i] && w.isSimilarTo(words[i])){
                    if(target.equals(words[i]))
                        return w.getCount() + 1;
                    used[i] = true;
                    q.add(new Word(words[i], w.getCount() + 1));
                }
            }
        }
        return answer;
    }
    
    class Word{
        private String word;
        private int count;
        Word(String word, int count){
            this.word = word;
            this.count = count;
        }
        String getString(){
            return word;
        }
        int getCount(){
            return count;
        }
        boolean isSimilarTo(String target){
            int diff = 0;
            for(int i=0; i<word.length(); i++)
                if(word.charAt(i) != target.charAt(i) && ++diff > 1)
                    return false;
            
            return diff == 1;
        }
        boolean equals(String target){
            return word.equals(target);
        }
    }
}