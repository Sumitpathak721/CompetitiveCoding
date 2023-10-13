
//  * // This is the MountainArray's API interface.
//  * // You should not implement it, or speculate about its implementation
#include<bits/stdc++.h>
using namespace std;
class MountainArray {
private:
    vector<int>arr;
public:
    void set(vector<int>tar){
        arr = tar;
    }
    int get(int index){
        return arr[index];
    }
    int length(){
        return arr.size();
    };
};

class Solution {
    int peakElem(MountainArray &arr){
        int len = arr.length();
        int l = 0,r = len-1,m = -1;
        while(l<=r){
            m = l+(r-l)/2;
            int valm = arr.get(m),minusm = arr.get(m-1),plusm = arr.get(m+1);
            if(minusm<valm && valm<plusm){
                l = m+1;
            }else if(minusm>valm && valm>plusm){
                r = m-1;
            }else{
                break;
            }
        }
        return m;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = peakElem(mountainArr);
        int l = 0,r = peak;
        int ans = -1;
        while(l<=r){
            int m = l + (r - l)/2,val = mountainArr.get(m);
            if(val==target){
                ans = m;
                r = m-1;
            }else if(val<target){
                l = m + 1;
            }else{
                r = m-1;
            }
        }
        if(ans!=-1) return ans;
        // ans = solve(peak+1,mountainArr.length(),target,mountain);
        l = peak+1;
        r = mountainArr.length()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            int val = mountainArr.get(m);
            if(val==target){
                ans = m;
                r = m-1;
            }else if(val>target){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return ans;
    }
};

int main(){
    Solution obj = Solution();
    MountainArray arr = MountainArray();
    vector<int>newArr = {3,5,3,2,0};
    arr.set(newArr);
    obj.findInMountainArray(0,arr);

    return 0;
}