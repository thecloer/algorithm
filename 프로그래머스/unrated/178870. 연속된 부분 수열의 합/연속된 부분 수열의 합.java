class Solution {
    public int[] solution(int[] sequence, int k) {
        int left = sequence.length, right = sequence.length-1, sum = 0;
        int[] answer = new int[2];
        while(left>=0){
            if(sum<k){
                if(--left>=0)
                    sum+=sequence[left];
            } else if(sum>k){
                sum-=sequence[right--];
            } else {
                if(left>0 && sequence[left-1]==sequence[right]){
                    left--;
                    right--;
                } else {
                    answer[0]=left;
                    answer[1]=right;
                    break;
                }
            }
        }
        return answer;
    }
}