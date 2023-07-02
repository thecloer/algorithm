class Solution {
    public int solution(int[] sides) {
        int max = 0, sum = 0;
        for(int s:sides){
            max = Math.max(max,s);
            sum += s;
        }
        return max < sum-max ? 1 : 2;
    }
}