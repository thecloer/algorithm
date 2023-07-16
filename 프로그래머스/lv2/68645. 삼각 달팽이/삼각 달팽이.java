class Solution {
    public int[] solution(int n) {
        int[] answer = new int[n*(n+1)/2];
        for(int step=1, N=(n+2)/3, w=n-1, val=1, idx=0; step<=N; w-=3, idx+=4*step++){
            if(w==0){
                answer[idx]=val;
                break;
            }
            for(int i=0; i<w; i++){
                answer[idx]=val++;
                idx+=2*step-1+i;
            }
            for(int i=0; i<w; i++){
                answer[idx++]=val++;
            }
            for(int i=0; i<w; i++){
                answer[idx]=val++;
                idx-=n+1-step-i;
            }
        }
        return answer;
    }
}