import java.util.*;
class Solution {
    public int solution(int[] stones, int k) {
        int answer=Integer.MAX_VALUE;
        for(int head=0; head<stones.length-k+1; head++){
            if(stones[head]>=answer)
                continue;

            int maxIdx = head;
            for(int i=head+1; i<head+k && i<stones.length; i++)
                if(stones[i] >= stones[maxIdx])
                    maxIdx = i;
            PriorityQueue<Integer> maxQueue = new PriorityQueue<Integer>((a,b)->b.compareTo(a));
            
            answer = Math.min(answer, stones[maxIdx]);
            head = maxIdx;
        }
        return answer;
    }
}