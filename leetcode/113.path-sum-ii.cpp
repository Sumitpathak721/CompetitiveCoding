/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

// @lc code=start

//  * Definition for a binary tree node.
// #include<bits/stdc++.h>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
private:
    vector<vector<int>>ans;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>arr;
        helper(root,targetSum,arr);
        return ans;
    }
    void helper(TreeNode* root, int targetSum,vector<int>arr){
        if(!root){
            return;
        }
        targetSum -=root->val;
        arr.push_back(root->val);
        if(targetSum==0 && !root->left && !root->right){
            ans.push_back(arr);
        }
        helper(root->left,targetSum,arr);
        helper(root->right,targetSum,arr);
    }

};
// @lc code=end
// int main(){
//     Solution obj = Solution();
//     // 2,null,-3]
//     TreeNode* root = new TreeNode(-2);
//     root->right = new TreeNode(-3);
//     obj.pathSum(root,-5);
//     return 0;
// }