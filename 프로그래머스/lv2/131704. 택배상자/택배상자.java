import java.util.*;
class Solution {
    public int solution(int[] order) {
        Stack<Integer> sub = new Stack();
        int answer=0;
        for(int i=1, p=0; i<=order.length; i++){
            sub.push(i);
            while(!sub.isEmpty() && sub.peek() == order[p]){
                sub.pop();
                answer++;
                p++;
            }
        }
        
        return answer;
    }
}