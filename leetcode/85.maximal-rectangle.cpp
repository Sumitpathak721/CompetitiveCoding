/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
// #include<bits/stdc++.h>
// using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int maxArea =0;
        int m = mat.size(),n = mat[0].size();
        vector<vector<int>>heights(m+1,vector<int>(n+1,0));
        stack<int>stk;
        for(int i=m-1;i>-1;i--){
            stk = stack<int>();
            vector<int>left(n),right(n);
            for(int j=0;j<n;j++){
                int h1,m1,h2;
                if(mat[i][j]!='0'){
                    heights[i][j] = heights[i+1][j]+(mat[i][j]-'0');
                }
                while(!stk.empty() && heights[i][stk.top()]>=heights[i][j]){
                    stk.pop();
                }
                if(stk.empty()){
                    left[j] = 0;
                }else{
                    left[j] = stk.top()+1;
                }
                stk.push(j);
            }
            stk = stack<int>();
            for(int j=n-1;j>-1;j--){
                while(!stk.empty() && heights[i][stk.top()]>=heights[i][j]){
                    stk.pop();
                }
                if(stk.empty()){
                    right[j] = n-1;
                }else{
                    right[j] = stk.top()-1;
                }
                stk.push(j);
            }
            for(int j=0;j<n;j++){
                int h = heights[i][j];
                int area = heights[i][j]*(right[j]-left[j]+1);
                maxArea = max(maxArea,area);
            }
        }
        return maxArea;
    }
};
// @lc code=end

// int main(){
//     Solution obj = Solution();
//     vector<vector<char>>inp = {
//         {'1','0','1','0','0'},
//         {'1','0','1','1','1'},
//         {'1','1','1','1','1'},
//         {'1','0','0','1','0'}};
//     cout <<  obj.maximalRectangle(inp);
//     return 0;
// }