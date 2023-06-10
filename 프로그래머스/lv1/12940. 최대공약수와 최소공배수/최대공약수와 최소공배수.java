class Solution {
    public int[] solution(int n, int m) {
        int gcd = GCD(n,m);
        int lcm = LCM(n,m,gcd);
        return new int[]{gcd,lcm};
    }
    int GCD(int a, int b){
        if(b==0) return a;
        return GCD(b, a%b);
    }
    int LCM(int a, int b, int gcd){
        return (int)((long)a*b/gcd);
    }
}