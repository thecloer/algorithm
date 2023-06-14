import java.util.*;
class Solution {
    public int[] solution(int k, int[] score){
        int[] answer = new int[score.length];
        PriorityQueue<Integer> heap = new PriorityQueue();
        for(int i=0; i<score.length; i++){
            heap.add(score[i]);
            if(heap.size()>k)
                heap.remove();
            answer[i] = heap.peek();
        }
        return answer;
    }
}