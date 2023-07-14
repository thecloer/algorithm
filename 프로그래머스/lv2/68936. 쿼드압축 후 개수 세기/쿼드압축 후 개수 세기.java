class Solution {
    private int[] result = new int[2];
    public int[] solution(int[][] arr) {
        compress(arr, 0, 0, arr.length);
        return result;
    }
    void compress(int[][] image, int rowStart, int colStart, int width){
        int num = image[rowStart][colStart];
        for(int r=rowStart; r<rowStart+width; r++){
            for(int c=colStart; c<colStart+width; c++){
                if(image[r][c]!=num){
                    compress(image, rowStart, colStart, width/2);
                    compress(image, rowStart+width/2, colStart, width/2);
                    compress(image, rowStart, colStart+width/2, width/2);
                    compress(image, rowStart+width/2, colStart+width/2, width/2);
                    return;
                }
            }
        }
        
        result[num]++;
    }
}