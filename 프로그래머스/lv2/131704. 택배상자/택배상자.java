import java.util.*;
class Solution {
    public int solution(int[] order) {
        Stack<Integer> sub = new Stack();
        int answer=0;
        for(int i=1, p=0; i<=order.length && p<order.length; i++){
            if(i == order[p]){
                answer++;
                p++;
                while(!sub.isEmpty()){
                    if(sub.peek() != order[p])
                        break;
                    sub.pop();
                    p++;
                    answer++;
                }
            } else
                sub.push(i);
        }
        
        return answer;
    }
}