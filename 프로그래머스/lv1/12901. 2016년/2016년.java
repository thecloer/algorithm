class Solution {
    public String solution(int a, int b) {
        final String[] week = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
        final int[] month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int diff = b-1;
        for(int i=0; i<a-1; i++)
            diff += month[i];
        return week[diff%7];
    }
}