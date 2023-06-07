import java.util.*;
class Solution {
    public int solution(String s) {
        int answer = 0;
        Stack<Character> stack = new Stack();
        char c;
        rotate: for(int start=0; start<s.length(); start++){
            for(int i=0; i<s.length(); i++){
                c = s.charAt((start+i)%s.length());
                if(c == '('|| c=='[' || c =='{') stack.push(c);
                else if((c == ')'|| c==']' || c =='}') && (stack.size() < 1 || !isPair(stack.pop(),c))) 
                    continue rotate;
            }
            if(stack.size()==0) answer++;
        }
        return answer;
    }
    boolean isPair(char open, char close){
        if(open=='('&&close==')') return true;
        if(open=='['&&close==']') return true;
        if(open=='{'&&close=='}') return true;
        return false;
    }
}