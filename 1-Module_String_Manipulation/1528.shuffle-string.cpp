/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */

// @lc code=start
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string temp;
        for(int i=0;i<indices.size();i++){
            // temp[indices[i]]=s[i];
            for(int k=0;k<indices.size();k++){
                if(indices[k]==i){
                    temp+=s[k];
                }
            }
        }
        return temp;
    }
};
// @lc code=end

