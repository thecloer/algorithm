class Solution {
    public int[] solution(int brown, int yellow) {
        int width = brown/2 - 1, height=3;
        for(; height<=brown/4 + 1; height++){
            width = brown/2 + 2 - height;
            if(width*height == brown + yellow) break;
        }
        int[] answer = new int[2];
        answer[0] = width;
        answer[1] = height;
        return answer;
    }
}