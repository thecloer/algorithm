class Solution {
    public int solution(int n) {
        int i = 2;
        while(n%i!=1)
            i++;
        return i;
    }
}