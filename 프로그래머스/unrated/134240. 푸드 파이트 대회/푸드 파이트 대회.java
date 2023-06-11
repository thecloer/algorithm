import java.util.*;
class Solution {
    public String solution(int[] food) {
        StringBuilder sb = new StringBuilder();
        order(1,food,sb);
        return sb.toString();
    }
    void order(int index, int[] food, StringBuilder sb){
        if(index>=food.length){
            sb.append(0);
            return;
        }
        
        for(int i=0; i<food[index]/2; i++)
            sb.append(index);
        order(index+1, food, sb);
        for(int i=0; i<food[index]/2; i++)
            sb.append(index);
    }
}