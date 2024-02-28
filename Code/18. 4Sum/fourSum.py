class Solution:
    def fourSum(self, nums, target):
        def helper(nums, target, start, res, temp, num_need):
            if num_need != 2:
                for i in range(start, len(nums) - num_need + 1):
                    if i > start and nums[i] == nums[i - 1]:
                        continue  # Skip duplicates to avoid duplicate combinations.
                    temp.append(nums[i])  # Add the current number to the combination.
                    helper(nums, target - nums[i], i + 1, res, temp, num_need - 1)  # Recursively find the next number(s).
                    temp.pop()  # Remove the last number to backtrack.
                return

            # If we need exactly 2 numbers, perform a two-pointer approach.
            l, r = start, len(nums) - 1
            while l < r:
                total = nums[l] + nums[r]
                if total < target:
                    l += 1
                elif total > target:
                    r -= 1
                else:
                    temp.append(nums[l])  # Add the left number to the combination.
                    temp.append(nums[r])  # Add the right number to the combination.
                    res.append(temp[:])  # Store the valid quadruplet in the result list.
                    temp.pop()  # Remove the right number to backtrack.
                    temp.pop()  # Remove the left number to backtrack.
                    l += 1
                    r -= 1
                    while l < r and nums[l] == nums[l - 1]:
                        l += 1  # Skip duplicates on the left.

        nums.sort()  # Sort the input list in ascending order.
        res = []  # Result list to store valid quadruplets.
        temp = []  # Temporary list to store combinations.
        helper(nums, target, 0, res, temp, 4)  # Call the helper function to find quadruplets.
        return res  # Return the result list containing unique quadruplets.