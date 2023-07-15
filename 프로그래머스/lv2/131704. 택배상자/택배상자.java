import java.util.*;
class Solution {
    public int solution(int[] order) {
        Stack<Integer> sub = new Stack();
        int answer=0, p=0;
        for(int i=1; i<=order.length;){
            if(i == order[p]){
                answer++;
                p++;
                i++;
            }else if(!sub.isEmpty() && order[p] == sub.peek()){
                answer++;
                p++;
                sub.pop();
            }else
                sub.push(i++);
        }
        
        while(!sub.isEmpty()){
            if(sub.pop() != order[p++])
                break;
            answer++;
        }
        return answer;
    }
}