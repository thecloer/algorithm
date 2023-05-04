class Solution {
    public int solution(int[] numbers, int k) {
        int pointer = 2 * (k-1) % numbers.length;
        return numbers[pointer];
    }
}