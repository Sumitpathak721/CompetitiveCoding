/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
// #include<bits/stdc++.h>
// using namespace std;
// //  * Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        return dfs(arr,0,arr.size());
    }
    TreeNode* dfs(vector<int> arr,int s,int e){
        if(s>e-1){
            return nullptr;
        }
        int m = (s+e)/2;
        TreeNode* newRoot = new TreeNode(arr[m]);
        newRoot->left = dfs(arr,s,m);
        newRoot->right = dfs(arr,m+1,e);
        return newRoot;
    }
};
// @lc code=end

// int main(){
//     ListNode* lst = new ListNode(-10);
//     lst->next = new ListNode(-3);
//     lst->next->next = new ListNode(0);
//     lst->next->next->next = new ListNode(5);
//     lst->next->next->next->next = new ListNode(9);
//     Solution obj = Solution();
//     obj.sortedListToBST(lst);
//     return 0;
// }