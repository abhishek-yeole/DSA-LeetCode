class Solution {
public:
    int threeSum(vector<int>& nums,int tar) 
    {
        int n=nums.size();
       int ans,diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int target = tar-nums[i];
            int l=i+1,h=n-1;
            while(l<h)
            {
                if(nums[l]+nums[h]<target)
                {
                    if(diff>abs((nums[l]+nums[h])-target))  
                    {
                        diff=abs((nums[l]+nums[h])-target);
                        ans=nums[l]+nums[h]+nums[i];
                    }
                    l++;
                }
                else if(nums[l]+nums[h]>target)
                {
                    if(diff>abs((nums[l]+nums[h])-target))  
                    {
                        diff=abs((nums[l]+nums[h])-target);
                        ans=nums[l]+nums[h]+nums[i];
                    }
                    h--;
                }
                else
                {
                    return tar;
                }
            }
            while(nums[i]==nums[i+1] && i+1<n-2) i++;
        }
        return ans;
    }
    int threeSumClosest(vector<int>& nums, int target)
    {
        return threeSum(nums,target);
        
    }
};