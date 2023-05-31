import java.util.*;
import java.util.stream.Collectors;
class Solution
{
    public int solution(int []A, int []B)
    {
        PriorityQueue<Integer> AQ= new PriorityQueue();
        PriorityQueue<Integer> BQ= new PriorityQueue(Collections.reverseOrder());
        for(int i=0; i<A.length;i++){
            AQ.add(A[i]);
            BQ.add(B[i]);
        }
        int answer = 0;
        
        while(!AQ.isEmpty())
            answer += AQ.poll() * BQ.poll();
        return answer;
    }
}