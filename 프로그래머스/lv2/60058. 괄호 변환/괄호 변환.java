import java.util.*;
class Solution {
    public String solution(String p) {
        return func(new StringBuilder(p)).toString();
    }
    StringBuilder func(StringBuilder s){
        if(s.length()==0)
            return s;
        StringBuilder u = new StringBuilder();
        StringBuilder v = new StringBuilder();
        Stack<Character> stack = new Stack();
        boolean isU=true, isRight=true;
        int[] counts = new int[2];
        
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(isU){
                u.append(c);
                counts[c=='('?0:1]++;
                if(counts[0]==counts[1])
                    isU=false;
                if(isRight){
                    if(c==')'){
                        if(stack.isEmpty() || stack.peek()==')')
                            isRight=false;
                        else
                            stack.pop();                        
                    } else
                        stack.push(c);
                }
            } else 
                v.append(c);
        }
        if(isRight)
            u.append(func(v));
        else {
            StringBuilder temp = new StringBuilder();
            temp.append('(').append(func(v)).append(')');
            for(int i=1; i<u.length()-1; i++)
                temp.append(u.charAt(i)=='('?')':'(');
            u=temp;
        }
        
        return u;
    }
}