import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        short zero = 0;
        short hit = 0;
        Set<Integer> winSet = Arrays.stream(win_nums).boxed().collect(Collectors.toSet());
        for(int n: lottos){
            if(n == 0) zero++;
            else if(winSet.contains(n)) hit++;
        }
        int[] answer = new int[2];
        
        answer[0] = getRank((short)(hit + zero)); 
        answer[1] = getRank(hit);
        return answer;
    }
    
    private int getRank(short hit){
        int rank = 7 - hit;
        return rank > 5 ? 6 : rank;
    }
}