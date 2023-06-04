class Solution {
    public int solution(int[] arr) {
        int answer = 1;
        for(int i:arr)
            answer = LCM(answer,i);
        
        return answer;
    }
    int LCM(int a, int b){
        return (a*b)/GCD(a,b);
    }
    int GCD(int a, int b){
        if(a<b){
            int temp = a;
            a = b;
            b = temp;
        }
        if(b==0) return a;
        return GCD(b, a%b);
    }
}