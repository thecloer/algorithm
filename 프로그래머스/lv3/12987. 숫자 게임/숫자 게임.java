import java.util.*;
class Solution {
    public int solution(int[] A, int[] B) {
        Arrays.sort(A);
        Arrays.sort(B);
        int answer = 0;
        for(int i=A.length-1, j=B.length-1; i>=0 && j>=0; i--){
            if(A[i]>B[j])
                continue;
            if(A[i]<B[j]){
                answer++;
                j--;
            } 
        }
        return answer;
    }
}