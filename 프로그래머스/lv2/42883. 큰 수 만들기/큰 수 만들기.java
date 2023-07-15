import java.util.*;
class Solution {
    public String solution(String number, int k) {
        char[] charArray = new char[number.length()-k];
        Stack<Character> stack = new Stack();
        for(char c:number.toCharArray()){
            while(!stack.isEmpty() && stack.peek()<c && k-->0)
                stack.pop();
            stack.push(c);
        }
        for(int i=0; i<charArray.length; i++)
            charArray[i] = stack.get(i);
        
        return new String(charArray);
    }
}