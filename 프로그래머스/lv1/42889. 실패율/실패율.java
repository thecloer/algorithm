import java.util.*;

class Solution {
    public Integer[] solution(int N, int[] stages) {
        int[] stageCount = new int[N+1];
        for(int stage: stages)
            stageCount[stage-1]++;

        double[] failRate = new double[N];
        int sum = 0;
        for(int i=0; i<N; i++){
            int total = stages.length - sum;
            failRate[i] = total == 0 ? 0 : (double)stageCount[i] / total;
            sum += stageCount[i];
        }
        
        Integer[] answer = new Integer[N];
        for(int i=0; i<N; i++)
            answer[i] = i + 1;
        
        Arrays.sort(answer, (i,j) -> Double.compare(failRate[j-1], failRate[i-1]));
        return answer;
    }
}