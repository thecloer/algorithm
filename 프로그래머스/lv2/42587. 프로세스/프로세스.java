import java.util.*;
class Solution {
    public int solution(int[] priorities, int location) {
        int head=0, p, max;
        Set<Integer> done = new HashSet();
        while(done.size() < priorities.length){
            head = next(head, priorities.length, done);
            max = head;
            for(int i=0; i<priorities.length; i++){
                p = (head + i)%priorities.length;
                if(!done.contains(p) && (priorities[p]>priorities[max])) 
                    max = p;
            }
            done.add(max);
            if(max == location) break;
            head = max;
        }
        
        return done.size();
    }
    int next(int before, int max, Set<Integer> done){
        while(before>=max || done.contains(before)){
            if(before>=max) before = 0;
            if(done.contains(before)) before++;
        }
        return before;
    }
}