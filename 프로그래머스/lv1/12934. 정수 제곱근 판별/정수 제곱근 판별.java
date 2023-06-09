class Solution {
    public long solution(long n) {
        int x = (int)Math.sqrt(n);
        return Math.pow(x,2) == n ? (long)(x+1)*(x+1) : -1;
    }
}