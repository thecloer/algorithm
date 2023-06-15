import java.util.*;
class Solution {
    public int solution(int k, int m, int[] score) {
        Integer[] arr = Arrays.stream(score)
                            .boxed()
                            .sorted(Collections.reverseOrder())
                            .toArray(Integer[]::new);
        
        int answer = 0;
        for(int i=m-1; i<arr.length; i+=m)
            answer += arr[i]*m;
        return answer;
    }
}