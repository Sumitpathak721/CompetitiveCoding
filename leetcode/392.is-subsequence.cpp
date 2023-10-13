/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0,c=0;
        for(c = 0;c<s.size();c++){
            while(i<t.size() && t[i]!=s[c]){
                i++;
            }

            if(i<t.size()){
                if(t[i]==s[c])
                    i++;
            }else{
                return 0;
            }
        }
        if(c==s.size()){
            return 1;
        }else{
            return 0;
        }
    }
};
// @lc code=end

