import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        int answer = 0;
        for(int s:scoville)
            heap.add(s);
        while(heap.size()>1){
            if(heap.peek()>=K)
                break;
            heap.add(heap.poll() + 2 * heap.poll());
            answer++;
        }
        if(heap.size()>0 && heap.peek() < K) answer = -1;
        
        return answer;
    }
}