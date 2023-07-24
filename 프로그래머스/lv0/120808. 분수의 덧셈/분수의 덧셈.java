class Solution {
    public int[] solution(int numer1, int denom1, int numer2, int denom2) {
        int numer = numer1*denom2 + numer2*denom1;
        int denom = denom1*denom2;
        int divisor = gcd(numer, denom);
        numer/=divisor;
        denom/=divisor;
        return new int[] {numer, denom};
    }
    int gcd(int a, int b){
        return (a%b==0) ? b : gcd(b, a%b);
    }
}