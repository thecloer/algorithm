class Solution {
    int solution(int[][] land) {
        for(int row=1; row<land.length; row++){
            for(int col=0; col<4; col++)
                land[row][col] += maxWithout(land[row-1], col);
        }
        return max(land[land.length-1]);
    }
    
    int max(int[] arr){
        int m=0;
        for(int i=0; i<arr.length; i++)
            if(m<arr[i]) 
                m = arr[i];
        return m;
    }
    int maxWithout(int[] arr, int excludedIndex){
        int m=0;
        for(int i=0; i<arr.length; i++)
            if(i!=excludedIndex && m<arr[i]) 
                m = arr[i];
        return m;
    }
}