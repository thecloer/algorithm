class Solution {
    public int solution(int price) {
        double rate=1;
        if(price >= 500_000) rate = 0.8;
        else if(price >= 300_000) rate = 0.9;
        else if(price >= 100_000) rate = 0.95;
        return (int)(price*rate);
    }
}