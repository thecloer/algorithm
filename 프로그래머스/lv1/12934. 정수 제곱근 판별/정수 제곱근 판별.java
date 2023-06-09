class Solution {
    public long solution(long n) {
        double x = Math.sqrt(n);
        if(x == (int)x) return (long)Math.pow((int)x+1,2);
        return -1;
    }
}