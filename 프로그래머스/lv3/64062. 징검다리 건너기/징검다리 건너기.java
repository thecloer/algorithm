import java.util.*;
class Solution {
    public int solution(int[] stones, int k) {
        int min=1, max=200000000, mid=(max+min)/2;
        while(min<max){            
            int count = 0;
            for(int s:stones){
                count = s>mid ? 0 : count+1;
                if(count==k) break;
            }
            if(count == k)
                max=mid;
            else
                min=mid+1;
            mid = (max+min)/2;
        }
        return mid;
    }
}