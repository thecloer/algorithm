class Solution {
    public int solution(int[] numbers, int k) {
        int answer = 0;
        int p = 0;
        while (k >= 2){
            k--;
            p += 2;
            if(p >= numbers.length){
                p -= numbers.length;
            }
        }
        return numbers[p];
    }
}