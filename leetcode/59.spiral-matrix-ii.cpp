/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        vector<vector<int>>v(n,vector<int>(n,0));
        int i = 0;//0->r,1->d,2->l,3->u
        int x = 0;
        int y = 0;
        int val = 1;
        while(val<n*n+1){
            if(i==0 && y<n && v[x][y]==0){
                v[x][y]=1;
                ans[x][y++]=val++;
            }else if(i==1 && x<n && v[x][y]==0){
                v[x][y]=1;
                ans[x++][y]=val++;
            }else if(i==2 && y>-1 && v[x][y]==0){
                v[x][y]=1;
                ans[x][y--]=val++;
            }else if(i==3 && x>-1 && v[x][y]==0){
                v[x][y]=1;
                ans[x--][y]=val++;
            }else{
                if(i==0){
                    y--;
                    x++;
                }else if(i==1){
                    x--;
                    y--;
                }else if(i==2){
                    y++;
                    x--;
                }else{
                    x++;
                    y++;
                }
                i = (i+1)%4;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution obj = Solution();
    vector<vector<int>>ans = obj.generateMatrix(3);
    for(auto arr:ans){
        for(int i:arr){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}