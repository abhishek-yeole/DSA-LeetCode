class Solution {
    public int maxArea(int[] height) {
        int water=0;
        int left=0;
        int right=height.length-1;

        while(left<right){
            int leftMax=height[left];
            int rightMax=height[right];

            water=Math.max(water,(right-left)*Math.min(leftMax,rightMax));
            if(leftMax<=rightMax){
                while(left<right && leftMax>=height[left]) left++;
            }
            else{
                while(left<right && rightMax>=height[right]) right--;
            }
        }
        return water;
    }
}