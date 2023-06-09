class Solution {
    public boolean solution(int x) {
        int xCopy = x;
        int sum = 0;
        while(xCopy>0){
            sum+=xCopy%10;
            xCopy /= 10;
        }
        return x%sum==0;
    }
}