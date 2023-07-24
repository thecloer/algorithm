class Solution {
    public int solution(int[] ingredient) {
        int answer=0, n=0;
        int[] stack = new int[ingredient.length];
        for(int curr:ingredient){
            stack[n++] = curr;
            if(n>=4 && stack[n-1]==1
               && stack[n-2]==3
               && stack[n-3]==2
               && stack[n-4]==1){
                answer++;
                n-=4;
            }
        }
        return answer;
    }
}