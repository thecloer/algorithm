import java.util.*;
class Solution {
    public long solution(String expression) {
        Expression e = new Expression(expression);
        StringBuilder operators = new StringBuilder();
        for(char c:e.getOperators())
            operators.append(c);
        
        Set<String> priorities = new HashSet();
        combination(priorities, operators.toString(), new StringBuilder());
        
        long answer = 0;
        boolean isStart = true;
        for(String priority:priorities) {
            if(isStart) isStart=false;
            else e.reset();
            answer = Math.max(answer, e.calculate(priority));
        }
        return answer;
    }
    
    void combination(Set<String> result, String input, StringBuilder sb){
        if(sb.length()==input.length()){
            result.add(sb.toString());
            return;
        }
        for(int i=0; i<input.length(); i++){
            char c = input.charAt(i);
            if(sb.indexOf(String.valueOf(c))<0){
                sb.append(c);
                combination(result, input, sb);
                sb.deleteCharAt(sb.length()-1);
            }
        }
    }
    
    class Expression {
        private class Token {
            Token prev = null;
            Token next = null;
        }
        private class Operand extends Token {
            long value;
            Operand(long value){
                this.value=value;
            }
        }
        private class Operator extends Token {
            char symbol;
            Operator(char symbol){
                this.symbol=symbol;
            }
        }
        String rawExpression;
        private Token head, tail;
        private char[] operators = {'*', '+', '-'};
        private Map<Character, ArrayList<Operator>> operatorMap = new HashMap();
        Expression(String rawExpression){
            this.rawExpression = rawExpression;
            tokenize();
        }
        void reset(){
            head=null;
            tail=null;
            tokenize();
        }
        private void tokenize(){
            StringBuilder num = new StringBuilder();
            for(char c:this.rawExpression.toCharArray()){
                
                boolean isOperator = false;
                for(char o:operators){
                    if(c==o){
                        isOperator = true;
                        break;
                    }
                }
                
                if(isOperator) {
                    Token prevNumber = new Operand(Integer.valueOf(num.toString()));
                    Token currOperator = new Operator(c);
                    prevNumber.next = currOperator;
                    currOperator.prev = prevNumber;
                    
                    if(head==null) {
                        head = prevNumber;
                    } else {
                        tail.next = prevNumber;
                        prevNumber.prev = tail;
                    }
                    tail = currOperator;
                    num.setLength(0);
                    
                    ArrayList<Operator> list = operatorMap.getOrDefault(c, new ArrayList());
                    list.add((Operator)currOperator);
                    operatorMap.put(c, list);
                } else 
                    num.append(c);
            }
            Token lastNum = new Operand(Long.valueOf(num.toString()));
            tail.next = lastNum;
            lastNum.prev = tail;
            tail = lastNum;
        }
        Set<Character> getOperators() {
            return operatorMap.keySet();
        }
        
        long calculate(String priority){
            for(char operator:priority.toCharArray()){
                for(Operator o:operatorMap.get(operator)){
                    Operand prevOperand = (Operand)o.prev;
                    Operand nextOperand = (Operand)o.next;
                    switch(o.symbol){
                        case '*': prevOperand.value *= nextOperand.value;
                            break;
                        case '+': prevOperand.value += nextOperand.value;
                            break;
                        case '-': prevOperand.value -= nextOperand.value;
                            break;
                    }
                    prevOperand.next = nextOperand.next;
                    if(prevOperand.next != null)
                        prevOperand.next.prev = prevOperand;
                }
            }
            return Math.abs(((Operand)head).value);
        }
        
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            Token pointer = head;
            while(pointer!=null){
                if(pointer instanceof Operand)
                    sb.append(((Operand)pointer).value).append(' ');
                else 
                    sb.append(((Operator)pointer).symbol).append(' ');
                pointer = pointer.next;
            }
            return sb.toString();
        }
    }
}