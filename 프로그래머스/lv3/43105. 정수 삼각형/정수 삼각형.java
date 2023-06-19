class Solution {
    public int solution(int[][] triangle) {
        for(int i=1; i<triangle.length; i++)
            for(int j=0; j<=i; j++)
                triangle[i][j] += max(triangle[i-1],
                                     j==0?0:j-1,
                                     j==i?j-1: j);
        return max(triangle[triangle.length-1],0,triangle.length-1);
    }
    int max(int[] arr, int start, int end){
        int m = arr[start];
        for(int i=start+1; i<=end; i++)
            if(m<arr[i])
                m=arr[i];
        return m;
    }
}