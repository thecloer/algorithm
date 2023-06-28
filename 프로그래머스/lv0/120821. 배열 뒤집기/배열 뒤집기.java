class Solution {
    public int[] solution(int[] list) {
        for(int i=0, n=list.length/2; i<n; i++){
            int tmp = list[i];
            list[i] = list[list.length-1-i];
            list[list.length-1-i] = tmp;
        }
        return list;
    }
}