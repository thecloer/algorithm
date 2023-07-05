import java.util.*;
class Solution {
    public int solution(int[] numbers) {
        PriorityQueue<Integer> q = new PriorityQueue(Comparator.reverseOrder());
        for(int n:numbers)
            q.add(n);
        return q.poll() * q.poll();
    }
}