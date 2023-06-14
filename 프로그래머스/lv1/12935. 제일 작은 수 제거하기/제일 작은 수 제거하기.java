class Solution {
    public int[] solution(int[] arr) {
        if(arr.length < 2) return new int[] {-1};
        int min = 0; 
        for(int i=1; i<arr.length; i++)
            if(arr[min]>arr[i])
                min = i;
        
        int[] answer = new int[arr.length -1];
        int j = 0;
        for(int i=0; i<answer.length; i++){
            if(i==min) j++;
            answer[i] = arr[j++];
        }
        return answer;
    }
}