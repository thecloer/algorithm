import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] rest = new int[progresses.length];
        for(int i=0; i<progresses.length; i++)
            rest[i] = (int)Math.ceil((double)(100 - progresses[i])/speeds[i]);

        LinkedList<Integer> answer = new LinkedList();
        int temp = rest[0];
        int count = 1;
        for(int i=1; i<rest.length; i++){
            if(rest[i]>temp){
                answer.add(count);
                temp = rest[i];
                count = 1;
            } else count++;
        }
        answer.add(count);
        
        return answer.stream().mapToInt(i->i).toArray();
    }
}