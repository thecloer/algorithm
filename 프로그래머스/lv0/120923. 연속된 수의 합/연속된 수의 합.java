class Solution {
    public int[] solution(int num, int total) {
        int[] answer = new int[num];
        for(int i=0, a=(2*total/num - num + 1)/2; i<num; i++)
            answer[i] = a+i;
        return answer;
    }
}