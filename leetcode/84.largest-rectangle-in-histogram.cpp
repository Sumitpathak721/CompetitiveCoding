/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        vector<int>left(heights.size(),-1);
        vector<int>right(heights.size(),-1);
        for(int i=0;i<heights.size();i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty()){
                left[i] = 0;
            }else{
                left[i] = stk.top()+1;
            }
            stk.push(i);
        }
        stk = stack<int>();
        for(int i=heights.size()-1;i>-1;i--){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty()){
                right[i] = heights.size()-1;
            }else{
                right[i] = stk.top()-1;
            }
            int temp = right[i];
            stk.push(i);
        }
        int maxArea = 0,area=0;
        for(int i=0;i<heights.size();i++){
            area = heights[i]*(right[i]-left[i]+1);
            if(area>maxArea){
                maxArea = area;
            }
        }
        return maxArea;
    }
};
// @lc code=end

int main(){
    Solution obj = Solution();
    vector<int>arr = {2,1,5,6,2,3};
    obj.largestRectangleArea(arr);
    return 0;
}