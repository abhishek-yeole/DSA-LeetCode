class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {}; // If there are fewer than 4 elements, return an empty vector.
        }
        sort(nums.begin(), nums.end()); // Sort the input array in ascending order.
        vector<int> temp; // Temporary vector to store combinations.
        vector<vector<int>> res; // Result vector to store valid quadruplets.
        helper(nums, target, 0, res, temp, 4); // Call the helper function to find quadruplets.
        return res; // Return the result vector containing unique quadruplets.
    }
    
    // Helper function to find unique quadruplets using recursion.
    void helper(vector<int>& nums, long target, int start, vector<vector<int>>& res, vector<int>& temp, int numneed) {
        // If we need more than 2 numbers, we're looking for the first number in the combination.
        if (numneed != 2) {
            for (int i = start; i < nums.size() - numneed + 1; i++) {
                if (i > start && nums[i] == nums[i - 1]) {
                    continue; // Skip duplicates to avoid duplicate combinations.
                }
                temp.push_back(nums[i]); // Add the current number to the combination.
                helper(nums, target - nums[i], i + 1, res, temp, numneed - 1); // Recursively find the next number(s).
                temp.pop_back(); // Remove the last number to backtrack.
            }
            return;
        }
        
        // If we need exactly 2 numbers, perform a two-pointer approach.
        int l = start;
        int r = nums.size() - 1;
        while (l < r) {
            long sum = static_cast<long>(nums[l]) + static_cast<long>(nums[r]);
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                temp.push_back(nums[l]); // Add the left number to the combination.
                temp.push_back(nums[r]); // Add the right number to the combination.
                res.push_back(temp); // Store the valid quadruplet in the result vector.
                temp.pop_back(); // Remove the right number to backtrack.
                temp.pop_back(); // Remove the left number to backtrack.
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) {
                    l++; // Skip duplicates on the left.
                }
            }
        }
    }
};