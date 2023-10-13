/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start

//  * Definition for singly-linked list.
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        vector<ListNode*>arr;
        unordered_map<int,int>m;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp);
            m[temp->val]++;
            temp= temp->next;
        }
        ListNode* newHead = new ListNode(-1);
        ListNode* itr = newHead;
        for(ListNode* node:arr){
            if(m[node->val]==1){
                itr->next = new ListNode(node->val);
                itr = itr->next;
            }
        }
        return newHead->next;
    }
};
// @lc code=end

int main(){
    Solution obj = Solution();
    ListNode* lst = new ListNode(1);
    lst->next = new ListNode(2);
    lst->next->next = new ListNode(3);
    lst->next->next->next = new ListNode(3);
    lst->next->next->next->next = new ListNode(4);
    lst->next->next->next->next->next = new ListNode(4);
    lst->next->next->next->next->next->next = new ListNode(5);
    obj.deleteDuplicates(lst);
    return 0;
}