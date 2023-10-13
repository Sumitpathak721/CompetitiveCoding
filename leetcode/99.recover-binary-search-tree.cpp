/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */

// @lc code=start
// using namespace std;

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
public:
    TreeNode* first,*pre,*last;
    void recoverTree(TreeNode* root) {
        pre = root;
        TreeNode *root1 = root;
        while(root1->left){
            pre = root1->left;
            root1 = root1->left;
        }
        inorder(root);
        swap(first->val,last->val);
    }
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        
        if(pre->val>root->val){
            if(!first){
                first = pre;
            }
            last = root;
        }
        pre = root;
        inorder(root->right);
    }
};
// @lc code=end

// int main(){
//     TreeNode* root = new TreeNode(3);
//     root->left = new TreeNode(1);
//     root->right = new TreeNode(4);
//     root->right->left = new TreeNode(2);
//     Solution obj = Solution();
//     obj.recoverTree(root);
//     return 0;
// }