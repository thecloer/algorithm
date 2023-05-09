class Solution {
    public int solution(int[] array) {
        int answer = 0;
        
        String str = "";
        for(int num: array)
            str += num;
        
        for(char c:str.toCharArray())
            if(c == '7')
                answer++;
                
        return answer;
    }
}