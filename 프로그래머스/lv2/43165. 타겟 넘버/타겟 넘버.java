import java.util.*;
class Solution {
    public int solution(int[] numbers, int target) {
        int total = 0;
        for(int i=0; i<numbers.length; i++) total += numbers[i];
        
        return dfs(numbers, 0, 0, total, target);
    }
    
    int dfs(int[] nums, int depth, int prev, int rest, int target){
        if(depth >= nums.length) return prev == target? 1 : 0;
        if(prev + rest < target || prev - rest > target) return 0;
        return dfs(nums, depth+1, prev+nums[depth], rest-nums[depth], target)
             + dfs(nums, depth+1, prev-nums[depth], rest+nums[depth], target);
    }
    
}