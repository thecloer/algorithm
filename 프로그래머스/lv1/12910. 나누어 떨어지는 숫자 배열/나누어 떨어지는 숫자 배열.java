import java.util.*;
class Solution {
    public int[] solution(int[] arr, int divisor) {
        List<Integer> answer = new LinkedList();
        for(int a:arr)
            if(a%divisor==0)
                answer.add(a);
        if(answer.isEmpty()) return new int[] {-1};
    
        return answer.stream().sorted().mapToInt(i->i).toArray();
    }
}