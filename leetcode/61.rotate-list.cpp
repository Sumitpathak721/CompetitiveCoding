/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        vector<ListNode*>arr;
        while(temp!=nullptr){
            arr.push_back(temp);
            temp = temp->next;
        }
        if(arr.size()==1){
            return head;
        }
        int start = arr.size()-k%arr.size();
        if(start!=0){
            arr[(start-1)%arr.size()]->next = nullptr;
        }
        int prev = start, curr = (start+1)%arr.size();
        ListNode* tem = arr[start];
        while(curr!=1){
            arr[prev]->next = arr[curr];
            prev = curr;
            curr = (curr+1)%arr.size();
        }
        return arr[start];
    }
};
// @lc code=end
int main(){
    Solution obj = Solution();
    ListNode* lst = new ListNode(1);
    lst->next = new ListNode(2);
    lst->next->next = new ListNode(3);
    lst->next->next->next = new ListNode(4);
    lst->next->next->next->next = new ListNode(5);
    obj.rotateRight(lst,2);
    return 0;
}
