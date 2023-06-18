class Solution {
    public String solution(int n) {
        StringBuilder ans = new StringBuilder();
        for(int i=0; i<n; i++)
            ans.append(i%2==0?'수':'박');
        return ans.toString();
    }
}