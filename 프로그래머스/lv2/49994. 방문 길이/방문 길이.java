import java.util.*;
class Solution {
    public int solution(String dirs) {
        int[] pos = {0, 0};
        Set<String>[] used = new HashSet[2];
        for(int i=0; i<used.length; i++)
            used[i] = new HashSet();
        
        for(char c:dirs.toCharArray()){
            int d = c=='L'||c=='R'? 0 : 1;
            int offset = c=='L'||c=='D'? -1 : 1;
            int next = pos[d]+offset;
            if(next<-5 || next>5) continue;
            used[d].add(String.format("%d %d",
                                       pos[(d+1)%2],
                                       Math.min(pos[d], next)));
            pos[d] = next;
        }
        
        return used[0].size() + used[1].size();
    }
}