class Solution {
    public String solution(int n) {
        StringBuilder sb = new StringBuilder();
        int[] nums = {4,1,2};
        while(n>0){
            int rest = n%3;
            sb.insert(0,nums[rest]);
            n=n/3 + (rest==0?-1:0);
        }
        return sb.toString();
    }
}