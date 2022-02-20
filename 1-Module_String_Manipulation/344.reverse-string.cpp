/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int x,y;
        for(x=0,y=s.size()-1;x<=y;x++,y--){
            temp=s[x];
            s[x]=s[y];
            s[y]=temp;
        }
        
    }
};
// @lc code=end

