/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start

class Solution {
public:
    bool isPalindrome(string s) {
        string a;
        int valtoadd=0;
        for(int i=0;i<s.length();i++){
            if((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122)||(s[i]>='0' && s[i]<='9')){
                if(s[i]<=90){
                    valtoadd = 32;
                }
                a+=s[i]+valtoadd;
                valtoadd=0;
                // cout<<s[i];
            }
        }
        int x;
        int y;
        if(a.length()<=1){
            return true;
        }
        for(x=0,y=a.length()-1;x<=y;x++,y--){
            if(a[x] != a[y]){
                return false;
            }
        }
        return true;

    }
};
// @lc code=end

