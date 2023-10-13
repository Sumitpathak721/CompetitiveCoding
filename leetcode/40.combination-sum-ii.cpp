/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;
class Solution
{
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> arr;
        int i = 0;
        helper(candidates,target,arr,0);
        return ans;
    }
    void helper(vector<int> &candidates, int target,vector<int>arr,int idx){
        if(target==0){
            ans.push_back(arr);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(target<candidates[i]) break;
            arr.push_back(candidates[i]);
            if(candidates[i]==target){
                ans.push_back(arr);
                return;
            }
            helper(candidates,target-candidates[i],arr,i+1);
            arr.pop_back();
        }
    }
};
// @lc code=end
