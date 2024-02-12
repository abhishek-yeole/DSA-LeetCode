class Solution {
    public int[] twoSum(int[] nums, int target) {
        int len = nums.length;
        int[] res = new int[2];

        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                if (nums[i] + nums[j] == target) {
                    res[0] = i;
                    res[1] = j;
                    break;
                }
            }
        }
        return res;
    }
}


/* Runtime - 0ms - Beats 100.00% of users with Java */

class Solution {
    public int[] twoSum(int[] nums, int target) {
       int arr[] = new int[2];
       int j = 1;

       while(j < nums.length){
           for(int i = 0; i+j < nums.length; i++){
               if(target == nums[i]+nums[i+j]){
                   arr[0] = i;
                   arr[1]= i+j;
                   return arr;
               }
           }
           j++;
       }
       return arr;
    }
}