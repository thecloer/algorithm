class Solution {
    public int[] solution(int n) {
        int[] answer = new int[n*(n+1)/2];
        for(int step=0, idx=0, val=1; step<(n+1)/2; idx+=4*(++step)){
            int width = n-3*step-1;
            if(width==0){
                answer[idx]=val;
                break;
            }
            for(int i=0; i<3*width; i++){
                answer[idx] = val++;
                if(i/width==0)
                    idx+=2*step+1+i;
                else if(i/width==1)
                    idx++;
                else
                    idx-=n-step-i%width;       
            }
        }
        return answer;
    }
}