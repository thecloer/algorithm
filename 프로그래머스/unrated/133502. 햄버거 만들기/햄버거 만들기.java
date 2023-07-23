class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        int[] stack = new int[ingredient.length];
        for(int i=0, n=0; i<ingredient.length; i++){
            stack[n++] = ingredient[i];
            if(n>3 && stack[n-1]==1){
                boolean isBurger = true;
                for(int j=1; j<=4; j++){
                    if(stack[n-j]!=1+(4-j)%3){
                        isBurger=false;
                        break;
                    }
                }
                if(isBurger){
                    answer++;
                    n-=4;
                }
            }
        }
        return answer;
    }
}