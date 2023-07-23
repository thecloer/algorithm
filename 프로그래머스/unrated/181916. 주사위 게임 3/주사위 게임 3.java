import java.util.*;
class Solution {
    public int solution(int a, int b, int c, int d) {
        int[] arr = {a,b,c,d};
        Arrays.sort(arr);
        int ans = arr[0];
        if(ans==arr[3])
            ans=1111*arr[0];
        else if(arr[0]==arr[2] || arr[1]==arr[3])
            ans = (int)Math.pow(9*arr[1]+arr[0]+arr[3],2);
        else if(arr[0]==arr[1] && arr[2]==arr[3])
            ans = (int)(Math.pow(arr[3],2)-Math.pow(arr[0],2));
        else {
            int duplicatedValue = 0;
            for(int i=1; i<arr.length; i++){
                if(arr[i]==arr[i-1])
                    duplicatedValue = arr[i];
                ans *= arr[i];
            }
            ans = duplicatedValue==0 ? arr[0] : ans/(int)Math.pow(duplicatedValue,2);
        }
        return ans;
    }
}