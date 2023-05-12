import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        
        Stack<Integer> bucket = new Stack<Integer>();
        for(int move:moves)
            for(int[] row:board){
                if(row[move - 1] != 0){
                    if(!bucket.empty() && bucket.peek() == row[move - 1]) {
                        bucket.pop();
                        answer+=2;
                    } else bucket.push(row[move - 1]);
                    row[move - 1] = 0;
                    break;
                }
            }
        return answer;
    }
}