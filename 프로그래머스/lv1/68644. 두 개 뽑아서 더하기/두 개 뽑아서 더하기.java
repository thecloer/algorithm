import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
    // public Integer[] solution(int[] numbers) {
        
        HashSet<Integer> set = new HashSet();
        
        for(int i=0; i<numbers.length - 1; i++)
            for(int j=i+1; j<numbers.length; j++)
                set.add(numbers[i] + numbers[j]);
        
        int[] answer = set.stream().mapToInt(i -> i).sorted().toArray();
        // Integer[] answer = set.toArray(new Integer[set.size()]);
        // Arrays.sort(answer);
        return answer;
    }
}