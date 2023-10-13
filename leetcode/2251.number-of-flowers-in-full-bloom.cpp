/*
 * @lc app=leetcode id=2251 lang=cpp
 *
 * [2251] Number of Flowers in Full Bloom
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        unordered_map<int,int>allMap;
        set<int>allSet;
        for(auto arr:flowers){
            allMap[arr[0]]++;
            allMap[arr[1]]--;
            allSet.insert(arr[0]);
            allSet.insert(arr[1]);
        }
        vector<int>allArr;
        for(int i:allSet){
            allArr.push_back(i);
        }
        sort(allArr.begin(),allArr.end());
        vector<int>ans;
        for(int p:people){
            int it = lower_bound(allArr.begin(),allArr.end(),p)-allArr.begin()-1;
            if(it-1>p){
                ans.push_back(0);
            }else{
                ans.push_back(allMap[it]);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution obj = Solution();
    vector<vector<int>>flower = {{1,6},{3,7},{9,12},{4,13}};
    // 1 3 4 6 7 9 12 13
    vector<int>people = {2,3,7,11};
    for(int i:obj.fullBloomFlowers(flower,people)){
        cout << i << " ";
    };
    return 0;
}