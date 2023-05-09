class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for(int i=0; i<n; i++){
            String binary = Integer.toBinaryString(arr1[i] | arr2[i]);
            String placeholder = "0".repeat(n - binary.length());
            binary = placeholder + binary;
            answer[i] = binary.replaceAll("0", " ").replaceAll("1", "#");
        }
        return answer;
    }
}