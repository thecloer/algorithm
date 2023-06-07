import java.util.*;
class Solution {
    public int solution(int[] priorities, int location) {
        int done = 0;
        int loc = location;
        Queue<Integer> queue = new LinkedList();
        for(int i:priorities)
            queue.add(i);
        
        Arrays.sort(priorities);
        
        int p;
        while(!queue.isEmpty()){
            p = queue.poll();
            loc--;
            if(p == priorities[priorities.length - 1 - done]){
                done++;
                if(loc<0) break;
            } else {
                queue.add(p);
                if(loc<0) loc = queue.size() - 1;
            }
        }
        
        return done;
    }
}