class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int[][] matrix = new int[rows+1][columns+1];
        for(int i=1, k=1; i<=rows; i++)
            for(int j=1; j<=columns; j++)
                matrix[i][j] = k++;
        
        int[] answer = new int[queries.length];
        for(int i=0; i<queries.length; i++){
            int height = queries[i][2]-queries[i][0];
            int width = queries[i][3]-queries[i][1];
            int row = queries[i][0], col= queries[i][1];
            int value = matrix[row][col], min = value;
            for(int j=0; j<2*(width+height); j++){
                if(j<width) col++;
                else if(j<width+height) row++;
                else if(j<2*width+height) col--;
                else row--;
                value = override(matrix, row, col, value);
                min = Math.min(min, value);
            }
            
            answer[i] = min;
        }
        return answer;
    }
    
    int override(int[][] matrix, int row, int col, int value){
        int overridden = matrix[row][col];
        matrix[row][col] = value;
        return overridden;
    }
}