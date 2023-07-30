import java.util.*;
class Solution {
    public int solution(int[] stones, int k) {
        int answer = 200000000;
        Deque<int[]> window = new ArrayDeque();
        for(int i=0; i<stones.length; i++) {            
            if(!window.isEmpty() && window.peek()[0] <= i-k)
                window.poll();
            
            while(!window.isEmpty() && window.peekLast()[1] <= stones[i])
                window.pollLast();
            
            window.offer(new int[] {i, stones[i]});
            
            if(i >= k-1 && answer > window.peek()[1])
                answer = window.peek()[1];
        }
        return answer;
    }
}