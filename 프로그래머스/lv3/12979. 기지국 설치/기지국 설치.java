class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        for(int i=1, s=0; i<=n;){
            if(s<stations.length && i>=stations[s]-w && i<=stations[s]+w)
                i = stations[s++]+w + 1;
            else {
                answer++;
                i+=2*w+1;
            }
        }

        return answer;
    }
}