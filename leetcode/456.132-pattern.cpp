/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
// #include<bits/stdc++.h>
// using namespace std;
class Solution {
public:
   bool find132pattern(vector<int>& nums) {
        if(nums.size()<3){
            return false;
        }
        int first = nums[0],mid = nums[1],f = 1,i = 1,f2 = 0;
        while(i<nums.size()){
            if(f){
                if(nums[i-1]<=nums[i]){
                    mid = nums[i];
                    f2 = 1;
                }else if(f2){
                    f = 0;
                    continue;
                }else{
                    first = nums[i];
                }
            }else{
                if(nums[i-1]>=nums[i]){
                    if(nums[i]>first)
                        return true;
                }else{
                    f = 1;
                    first = nums[i-1];
                    mid =  nums[i];
                    f2 = 0;
                    continue;
                }
            }
            i++;
        }
        return false;
    }
};
// @lc code=end
int main(){
    Solution obj = Solution();
    vector<int>arr = {3,5,0,3,4};
    cout << obj.find132pattern(arr);
    return 0;
}
