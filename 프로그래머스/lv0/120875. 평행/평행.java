class Solution {
    public int solution(int[][] dots) {
        for(int i=1; i<4; i++){
            float slope1 = getSlope(dots[0], dots[i]);
            float slope2 = getSlope(dots[1+i%3], dots[1+(i+1)%3]);
            if(slope1==slope2 || slope1==-slope2)
                return 1;
        }
        return 0;
    }
    float getSlope(int[] p1, int[] p2){
        return (float)(p1[1]-p2[1])/(p1[0]-p2[0]);
    }
}