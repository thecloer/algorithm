import java.util.*;
class Solution {
    public String solution(String s, String skip, int index) {
        ArrayList<Character> alphabets = new ArrayList(26-skip.length());
        for(char c='a'; c<='z'; c++)
            if(skip.indexOf(c)<0)
                alphabets.add(c);
        StringBuilder sb = new StringBuilder();
        for(char c:s.toCharArray())
            sb.append(alphabets.get((alphabets.indexOf(c) + index)%alphabets.size()));
        return sb.toString();
    }
}