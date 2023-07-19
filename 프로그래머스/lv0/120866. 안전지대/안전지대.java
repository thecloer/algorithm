class Solution {
    public int solution(int[][] board) {
        for(int i=0; i<board.length; i++)
            for(int j=0; j<board[i].length; j++)
                if(board[i][j]==1)
                    for(int x=i-1; x<=i+1; x++)
                        for(int y=j-1; y<=j+1; y++)
                            if(x>=0 && x<board.length && y>=0 && y<board[i].length && board[x][y] != 1)
                                board[x][y]=2;
        int answer = 0;
        for(int i=0; i<board.length; i++)
            for(int j=0; j<board[i].length; j++)
                if(board[i][j]==0)
                    answer++;
        return answer;
    }
}