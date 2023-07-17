import java.util.*;
class Solution {
    public int[] solution(int[] sequence, int k) {
        Queue<Integer> q = new LinkedList();
        int sum=0;
        int[] answer = new int[2];
        for(int i=sequence.length-1; i>=0; i--){
            sum+=sequence[i];
            q.offer(i);
            while(!q.isEmpty() && sum>k){
                sum-=sequence[q.poll()];
            }
            if(sum==k){
                while(!q.isEmpty() && i>0 && sequence[q.peek()] == sequence[i-1]){
                    q.poll();
                    q.offer(--i);
                }
                answer[0] = i;
                answer[1] = q.peek();
                break;
            }
        }
        return answer;
    }
}