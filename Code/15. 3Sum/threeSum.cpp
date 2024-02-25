class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
          int l=i+1 ; int r=n-1;
             while(l<r){
                int s=nums[l]+nums[r] + nums[i];
                if(s== 0 && r!=l && l!=i){
                 st.insert({nums[i],nums[l],nums[r]});
                 l++;r--; }
                if(0 > s ) l++;
                if(0 < s ) r--;   }}
        vector<vector<int>> ans (st.begin(),st.end());
        return ans;
    }
};