/*
 * @lc app=leetcode id=1458 lang=cpp
 *
 * [1458] Max Dot Product of Two Subsequences
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
void print2D(vector<vector<int>>dp){
    for(auto arr:dp){
        for(auto i:arr){
            cout << i << " ";
        }
        cout << endl;
    }
}
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        int temp ;
        for(int i=1;i<=nums1.size();i++){
            for(int j=1;j<=nums2.size();j++){
                if(i==1){
                    if(j==1){
                        dp[i][j] = nums1[i-1]*nums2[j-1];
                    }else{
                        dp[i][j] = max(dp[i][j-1],nums1[i-1]*nums2[j-1]);
                    }
                }else{
                    if(j==1){
                        dp[i][j] = max(dp[i-1][j],nums1[i-1]*nums2[j-1]+dp[i-1][j-1]);
                    }else{
                        dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],nums1[i-1]*nums2[j-1]+dp[i-1][j-1]));
                    }
                }
            }
        }
        print2D(dp);
        return dp[nums1.size()][nums2.size()];
    }
};
// @lc code=end

int main(){
    Solution obj = Solution();
    vector<int>num1 = {-3,-8,3,-10,1,3,9},num2={9,2,3,7,-9,1,-8,5,-1,-1};
    obj.maxDotProduct(num1,num2);
    return 0;
}