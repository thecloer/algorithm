import java.util.*;
class Solution {
    public int solution(int[] ingredient) {
        int answer = 0, burger = 0;
        Stack<Integer> stack = new Stack();
        for(int curr: ingredient){
            if(stack.size()>2 && curr==1 && stack.peek()==3){
                do {
                    burger=stack.pop();
                } while(!stack.isEmpty() && stack.peek()==burger-1);
                if(burger==1){
                    answer++;
                    continue;
                }
                for(int i=burger; i<=3; i++)
                    stack.push(i);
            } 
            stack.push(curr);
        }
        return answer;
    }
}