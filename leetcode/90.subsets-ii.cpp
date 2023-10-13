/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    set<vector<int>>ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>arr;
        helper(arr,0,nums);
        vector<vector<int>>res;
        for(auto arr:ans){
            res.push_back(arr);
        }
        return res;
    }
    void helper(vector<int>arr,int idx,vector<int>nums){
        ans.insert(arr);
        if(idx==nums.size()){
            return;
        }
        helper(arr,idx+1,nums);
        arr.push_back(nums[idx]);
        helper(arr,idx+1,nums);
    }
};
// @lc code=end

